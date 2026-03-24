#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Item {
  std::string name;
  int price;
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
  os << "{name: " << item.name << ", price: " << item.price << "}";
  return os;
}

void print_all(const std::vector<Item>& items) {
  for (const auto& item : items) {
    std::cout << item << std::endl;
  }
}

int main() {
  std::vector<Item> items = {{"apple", 100}, {"banana", 150}, {"orange", 200}};

  std::cout << "値コピーで更新されない" << std::endl;
  for (auto item : items) {
    item.price += 10;
  }
  print_all(items);

  std::cout << std::endl;

  std::cout << "可変参照で更新する" << std::endl;
  for (auto& item : items) {
    item.price += 10;
  }
  print_all(items);
}
