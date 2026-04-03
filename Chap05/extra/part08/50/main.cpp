#include <functional>
#include <iostream>
#include <thread>
#include <atomic>

void increment(std::atomic<int>& counter) {
  for (int i = 0; i < 10000; ++i) {
    counter++;
  }
}

int main() {
  std::atomic<int> counter{0};

  std::thread t1(increment, std::ref(counter));
  std::thread t2(increment, std::ref(counter));
  std::thread t3(increment, std::ref(counter));

  t1.join();
  t2.join();
  t3.join();

  std::cout << counter.load() << '\n';
}