#include <iostream>
#include <memory>
#include <thread>


void print_value(std::shared_ptr<int> sp) {
  std::cout << "use_count: " << sp.use_count() << '\n';
  std::cout << "value: " << *sp << '\n';
}

int main() {
  auto sp = std::make_shared<int>(42);

  std::thread t1(print_value, sp);
  std::thread t2(print_value, sp);
  std::thread t3(print_value, sp);
  std::thread t4(print_value, sp);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}