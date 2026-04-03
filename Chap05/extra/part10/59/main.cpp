#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Counter {
public:
  void increment() {
    std::lock_guard<std::mutex> lock(m_);
    ++value_;
  }

  int get() const {
    std::lock_guard<std::mutex> lock(m_);
    return value_;
  }

private:
  mutable std::mutex m_;
  int value_ = 0;
};

int main() {
  Counter counter;

  constexpr int thread_count = 4;
  constexpr int increments_per_thread = 100000;

  std::vector<std::thread> threads;
  threads.reserve(thread_count);

  for (int i = 0; i < thread_count; ++i) {
    threads.emplace_back([&counter]() {
      for (int j = 0; j < increments_per_thread; ++j) {
        counter.increment();
      }
    });
  }

  for (auto& t : threads) {
    t.join();
  }

  std::cout << "final count = " << counter.get() << '\n';
}
