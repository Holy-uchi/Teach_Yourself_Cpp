#include <iostream>
#include <string>
#include <vector>

class product {
  int id;
  std::string name;
  int price;

public:
  explicit product(int id, std::string name, int price)
      : id(id), name(name), price(price) {}
  product() : product(-1, "default", -1) {}
  void dump() const {
    std::cout << "id: " << this->id << ", name: " << this->name
              << ", price: " << this->price << std::endl;
  }
};

int main() {
  std::vector<product> p;
  p.push_back(product{1, "smart phone", 60000});
  p.push_back(product{2, "tablet", 35000});
  p.push_back(product{});
  p.push_back(product{});

  for (auto& el : p) {
    el.dump();
  }
}
