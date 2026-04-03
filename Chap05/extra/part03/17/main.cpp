#include <iostream>
#include <memory>

struct Data {
  int x;

  Data(int v) : x(v) { std::cout << "construct\n"; }

  ~Data() { std::cout << "destruct\n"; }
};

int main() {
  // 直接newを使う
  // Dataオブジェクトの生成と、shared_ptrの管理用のデータ領域の生成の2段階になる
  // std::shared_ptr<Data> p1{new Data(10)};

  // make_sharedを使うと一度にまとめて生成できる
  std::shared_ptr<Data> p2 = std::make_shared<Data>(10);

  std::cout << p2->x << std::endl;
}
