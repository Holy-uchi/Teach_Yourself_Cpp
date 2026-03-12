#include <iostream>

class product {
  int id;
  int price;
  int stock;

public:
  int get_id();
  void set_id(int new_id);

  int get_price();
  void set_price(int new_price);

  int get_stock();
  void set_stock(int new_stock);

  void set_all(int new_id, int new_price, int new_stock);
};

int product::get_id() { return id; }
void product::set_id(int new_id) { id = new_id; }

int product::get_price() { return price; }
void product::set_price(int new_price) {
  if (new_price < 0) {
    std::cout << "エラー: 単価は0以上にしてください" << std::endl;
    return;
  }
  price = new_price;
}

int product::get_stock() { return stock; }
void product::set_stock(int new_stock) {
  if (new_stock < 0) {
    std::cout << "エラー: 在庫数は0以上にしてください" << std::endl;
    return;
  }
  stock = new_stock;
}

void product::set_all(int new_id, int new_price, int new_stock) {
  set_id(new_id);
  set_price(new_price);
  set_stock(new_stock);
}

int main() {
  product pen;

  pen.set_all(0, 100, 200);

  product* ptr = &pen;

  std::cout << "商品ID:" << ptr->get_id() << std::endl;
  std::cout << "単価:" << ptr->get_price() << std::endl;
  std::cout << "在庫数:" << ptr->get_stock() << std::endl;
}
