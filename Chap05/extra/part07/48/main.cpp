#include <iostream>
#include <memory>
#include <thread>

struct Data {
    int value = 42;
};

// 生ポインタを受け取るとそのポインタの寿命ががスレッドセーフであることを保証手段がない
// => shared_ptrにしてオブジェクトの寿命を保証する
// void work(Data* d) {
void work(std::shared_ptr<Data> p) {
  if (p) {
    std::cout << p->value << '\n';
  }
}

int main() {
  auto d = std::make_shared<Data>();

  std::thread t(work, d);

  t.join();
}