#include <iostream>
#include <memory>
#include <thread>

struct Data {
    int value = 0;
};

void print_value(std::shared_ptr<Data> sp) {
  std::cout << "print_value: " << sp->value << '\n';
}

int main() {
  auto sp = std::make_shared<Data>();

  std::thread t1(print_value, sp);
  std::thread t2(print_value, sp);

  t1.join();
  t2.join();
}