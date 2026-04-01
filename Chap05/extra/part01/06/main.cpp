#include <iostream>
#include <memory>
#include <string>
#include <utility>

struct Item {
  std::string name;

  Item(const std::string& n) : name(n) {}
};

int main() {
  auto p1 = std::make_unique<Item>("Book");
  auto p2 = std::move(p1);

  if (!p1) {
    std::cout << "p1 is nullptr\n";
  }

  if (p2) {
    std::cout << p2->name << "\n";
  }
}
