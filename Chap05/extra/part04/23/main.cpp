#include <iostream>
#include <memory>
#include <string>

struct Data {
    std::string value;

    Data(const std::string& v) : value(v) {}
};

int main() {
  std::weak_ptr<Data> wp;

  {
    auto p1 = std::make_shared<Data>("data");
    wp = p1;
    
    if (auto sp = wp.lock()) {
      std::cout << "wp => sp: " << sp->value << "\n";
    }
    std::cout << "ローカルスコープ終了\n";
  }

  if (auto sp = wp.lock()) {
    std::cout << "wp => sp: " << sp->value << "\n";
  } else {
    std::cout << "expired\n";
  }
}