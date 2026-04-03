#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void increment() {
    for (int i = 0; i < 10000; i++) {
        // ここを修正
        std::lock_guard<std::mutex> lock(m);
        counter++;
    }
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);

  t1.join();
  t2.join();

  std::cout << counter << std::endl;
}