#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 10000; i++) {
        counter++;
    }
}

int main() {
  std::thread w1(increment);
  std::thread w2(increment);

  w1.join();
  w2.join();

  std::cout << counter << std::endl;
}