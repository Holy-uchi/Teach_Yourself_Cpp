#include <iostream>

struct product {
  int id;
  int price;
  int stock;
};

void show_product(product* product) {
  std::cout << "商品ID: " << product->id << std::endl;
  std::cout << "単価: " << product->price << std::endl;
  std::cout << "在庫数: " << product->stock << std::endl;
}

int main() {
  product pen = {
      0,
      100,
      200,
  };

  show_product(&pen);
}
