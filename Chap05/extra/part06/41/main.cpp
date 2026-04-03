#include <iostream>
#include <mutex>
#include <thread>

struct Counter {
  int value = 0;
  std::mutex m;

  void increment() {
    std::lock_guard<std::mutex> lock(m);
    value++;
  }

  int get() {
    std::lock_guard<std::mutex> lock(m);
    return value;
  }
};

int main() {
  Counter c;
  std::thread t1([&] {
    for (int i = 0; i < 10000; ++i) {
      c.increment();
    }
  });
  std::thread t2([&] {
    for (int i = 0; i < 10000; ++i) {
      c.increment();
    }
  });

  t1.join();
  t2.join();

  std::cout << c.get() << std::endl;
}