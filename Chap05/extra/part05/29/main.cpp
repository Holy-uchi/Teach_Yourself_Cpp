#include <iostream>
#include <memory>

struct Foo : std::enable_shared_from_this<Foo> {
    std::shared_ptr<Foo> getPtr() {
        return shared_from_this();
    }
};

int main() {
  // Foo f;
  // auto p = f.getPtr(); // 問題あり: 理由=> fはstd::shared_ptr管理下ではない!!

  // fをshared_ptr管理下にすればgetPtrを使える
  auto f = std::make_shared<Foo>();
  auto p = f->getPtr();

  std::cout << "f.use_count(): " << f.use_count() << "\n";
}