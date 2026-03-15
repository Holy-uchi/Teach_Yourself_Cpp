#include <iostream>

class product {
  int price;

public:
  explicit product(int price) : price(price) {}

  int get_price() const { return price; }
  void set_price(int price) { this->price = price; }
};

int main() {
  product p{100};
  std::cout << p.get_price() << std::endl;
}
