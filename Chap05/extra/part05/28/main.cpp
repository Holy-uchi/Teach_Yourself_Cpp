#include <iostream>
#include <memory>

struct Foo : std::enable_shared_from_this<Foo> {
  std::shared_ptr<Foo> getPtr() {
    // ここを実装
    return shared_from_this();
  }
};

int main() {
  auto p1 = std::make_shared<Foo>();

  auto p2 = p1->getPtr();

  std::cout << "p1.use_count(): " << p1.use_count() << "\n";
}