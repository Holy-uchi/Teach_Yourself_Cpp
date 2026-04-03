#include <iostream>
#include <memory>
#include <thread>
#include <utility>

struct Data {
  int value;

  ~Data() {
    std::cout << "destructor\n";
  }
};

void work(std::unique_ptr<Data> ptr) {
  std::cout << ptr->value << std::endl;
  std::cout << "work() end\n";
}

int main() {
  auto p = std::make_unique<Data>(42);

  std::thread t(work, std::move(p));

  if (!p) {
    std::cout << "p is empty\n";
  }

  t.join();
  std::cout << "main() end\n";
}