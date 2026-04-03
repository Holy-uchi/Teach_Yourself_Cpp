#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using TaskId = int;

class Logger {
public:
  void log(const std::string& msg) {
    std::lock_guard<std::mutex> lock(m_);
    std::cout << msg << '\n';
  }

private:
  std::mutex m_;
};

class Task {
public:
  Task(TaskId id, std::string name) : id_(id), name_(std::move(name)) {}

  TaskId id() const { return id_; }
  const std::string& name() const { return name_; }

  void request_cancel() { cancelled_.store(true, std::memory_order_relaxed); }

  bool is_cancelled() const {
    return cancelled_.load(std::memory_order_relaxed);
  }

private:
  TaskId id_;
  std::string name_;
  std::atomic<bool> cancelled_{false};
};

class Worker {
public:
  Worker(int worker_id, Logger& logger)
      : worker_id_(worker_id), logger_(logger) {}

  void process(const std::shared_ptr<Task>& task) {
    logger_.log("[worker " + std::to_string(worker_id_) + "] start task " +
                std::to_string(task->id()) + " : " + task->name());

    for (int step = 0; step < 10; ++step) {
      if (task->is_cancelled()) {
        logger_.log("[worker " + std::to_string(worker_id_) + "] cancel task " +
                    std::to_string(task->id()));
        return;
      }

      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    logger_.log("[worker " + std::to_string(worker_id_) + "] finish task " +
                std::to_string(task->id()));
  }

private:
  int worker_id_;
  Logger& logger_;
};

class TaskManager {
public:
  explicit TaskManager(std::size_t worker_count)
      : logger_(std::make_unique<Logger>()) {
    workers_.reserve(worker_count);
    threads_.reserve(worker_count);

    for (std::size_t i = 0; i < worker_count; ++i) {
      workers_.push_back(
          std::make_unique<Worker>(static_cast<int>(i), *logger_));
    }

    for (std::size_t i = 0; i < worker_count; ++i) {
      threads_.emplace_back([this, i] { worker_loop(*workers_[i]); });
    }
  }

  ~TaskManager() {}

  std::shared_ptr<Task> create_task(std::string name) {
    auto id = next_id_.fetch_add(1, std::memory_order_relaxed);
    auto task = std::make_shared<Task>(id, std::move(name));

    {
      std::lock_guard<std::mutex> lock(index_mutex_);
      task_index_[id] = task;
    }

    return task;
  }

  void submit(const std::shared_ptr<Task>& task) {
    {
      std::lock_guard<std::mutex> lock(queue_mutex_);
      queue_.push(task);
    }
    cv_.notify_one();
  }

  void cancel(TaskId id) {
    std::shared_ptr<Task> task;

    {
      std::lock_guard<std::mutex> lock(index_mutex_);
      auto it = task_index_.find(id);
      if (it != task_index_.end()) {
        task = it->second.lock();
      }
    }

    if (task) {
      task->request_cancel();
      logger_->log("[manager] requested cancel for task " + std::to_string(id));
    }
  }

private:
  void worker_loop(Worker& worker) {
    while (true) {
      std::shared_ptr<Task> task;

      {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        cv_.wait(lock, [this] { return stopping_ || !queue_.empty(); });

        if (stopping_ && queue_.empty()) {
          return;
        }

        task = queue_.front();
        queue_.pop();
      }

      worker.process(task);

      {
        std::lock_guard<std::mutex> lock(index_mutex_);
        auto it = task_index_.find(task->id());
        if (it != task_index_.end() && it->second.expired()) {
          task_index_.erase(it);
        }
      }
    }
  }

  std::unique_ptr<Logger> logger_;
  std::vector<std::unique_ptr<Worker>> workers_;
  std::vector<std::thread> threads_;

  std::mutex queue_mutex_;
  std::condition_variable cv_;
  std::queue<std::shared_ptr<Task>> queue_;
  bool stopping_ = false;

  std::mutex index_mutex_;
  std::unordered_map<TaskId, std::weak_ptr<Task>> task_index_;

  std::atomic<TaskId> next_id_{0};
};

int main() {
  TaskManager manager(3);

  auto task1 = manager.create_task("load file");
  auto task2 = manager.create_task("parse data");
  auto task3 = manager.create_task("send report");

  manager.submit(task1);
  manager.submit(task2);
  manager.submit(task3);

  std::this_thread::sleep_for(std::chrono::milliseconds(120));
  manager.cancel(task2->id());

  std::this_thread::sleep_for(std::chrono::seconds(2));

  std::cout << "main done\n";
}
