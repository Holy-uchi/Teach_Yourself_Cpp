#include <iostream>
#include <memory>

struct Foo {
  // thisは生ポインタなので、全く新しい所有管理をするshared_ptrを作ってしまう。 
  std::shared_ptr<Foo> getPtr() {
      return std::shared_ptr<Foo>(this); // 問題あり
  }

  ~Foo() {
      std::cout << "destruct\n";
  }
};

int main() {
  auto foo1 = std::make_shared<Foo>();

  // this経由のshared_ptr作成は使わずにそのままコピー
  auto foo1_2 = foo1;

  std::cout << "foo1 count: " << foo1.use_count() << "\n";

  // もしくはenable_shared_from_thisを使う
}
