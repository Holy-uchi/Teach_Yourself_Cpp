#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int counter = 0;

void work() {
  int local_counter = 0;
  for (int i = 0; i < 10000; i++) {
    local_counter++;
  }

  std::lock_guard<std::mutex> lock(m);
  counter += local_counter;
}

int main() {
  std::thread t1(work);
  std::thread t2(work);

  t1.join();
  t2.join();

  std::cout << counter << std::endl;
}