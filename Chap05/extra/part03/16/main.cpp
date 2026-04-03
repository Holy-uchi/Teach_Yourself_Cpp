#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> p1 = std::make_shared<int>(42);
  std::cout << "count: " << p1.use_count() << "\n";

  {
    auto p2 = p1;
    std::cout << "count: " << p1.use_count() << "\n";
  }

  std::cout << "count: " << p1.use_count() << "\n";
}
