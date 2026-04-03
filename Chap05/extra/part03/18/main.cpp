#include <iostream>
#include <memory>

int main() {
  auto p1 = std::make_shared<int>(42);

  auto p2 = p1;
  std::cout << "count: " << p1.use_count() << "\n";

  auto p3 = p1;
  std::cout << "count: " << p1.use_count() << "\n";

  auto p4 = p1;
  std::cout << "count: " << p1.use_count() << "\n";
}