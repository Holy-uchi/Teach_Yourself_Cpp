#include <iostream>
#include <thread>

void work() {
    std::cout << "worker start\n";
    std::cout << "worker end\n";
}

int main() {
  std::thread t(work);
  t.join();
}