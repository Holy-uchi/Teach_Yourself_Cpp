// ApplicationはConfig, Logger, WoerkerPoolをunique_ptrで所有
// WorkerPoolはWorkersをunique_ptrで所有
// WorkerはConfig, Loggerを生ポインタで参照
// Worker -> Applicationの参照は生ポインタ

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

struct Config {
  std::string app_name;
  int worker_count;

  Config(std::string name, int count)
      : app_name(std::move(name)), worker_count(count) {}
};

struct Logger {
  void log(const std::string& message) const {
    std::cout << "[LOG] " << message << '\n';
  }
};

class Application;

class Worker {
public:
  Worker(int id, Config& config, Logger& logger, Application* app = nullptr)
      : id_(id), config_(config), logger_(logger), app_(app) {}

  void run() const;
  void print_app_link() const;

private:
  int id_;
  Config& config_;   // borrow: 必須
  Logger& logger_;   // borrow: 必須
  Application* app_; // optional borrow
};

class WorkerPool {
public:
  WorkerPool() = default;

  void add_worker(std::unique_ptr<Worker> worker) {
    workers_.push_back(std::move(worker));
  }

  void run_all() const {
    for (const auto& worker : workers_) {
      worker->run();
    }
  }

  void print_links() const {
    for (const auto& worker : workers_) {
      worker->print_app_link();
    }
  }

private:
  std::vector<std::unique_ptr<Worker>> workers_; // owns
};

class Application {
public:
  Application(std::string app_name, int worker_count)
      : config_(std::make_unique<Config>(std::move(app_name), worker_count)),
        logger_(std::make_unique<Logger>()),
        worker_pool_(std::make_unique<WorkerPool>()) {}

  void initialize() {
    logger_->log("Application initialize");

    for (int i = 0; i < config_->worker_count; ++i) {
      worker_pool_->add_worker(
          std::make_unique<Worker>(i, *config_, *logger_, this));
    }
  }

  void run() const {
    logger_->log("Application run");
    worker_pool_->print_links();
    worker_pool_->run_all();
  }

  const std::string& name() const { return config_->app_name; }

private:
  std::unique_ptr<Config> config_;          // owns
  std::unique_ptr<Logger> logger_;          // owns
  std::unique_ptr<WorkerPool> worker_pool_; // owns
};

void Worker::run() const {
  logger_.log("Worker #" + std::to_string(id_) +
              " running in app=" + config_.app_name);
}

void Worker::print_app_link() const {
  if (app_ != nullptr) {
    logger_.log("Worker #" + std::to_string(id_) +
                " sees Application: " + app_->name());
  } else {
    logger_.log("Worker #" + std::to_string(id_) + " has no Application link");
  }
}

int main() {
  Application app("DemoApp", 3);
  app.initialize();
  app.run();
}
