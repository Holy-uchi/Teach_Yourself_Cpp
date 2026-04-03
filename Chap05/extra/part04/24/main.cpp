#include <ios>
#include <iostream>
#include <memory>

int main() {
  std::weak_ptr<int> wp;
  {
    auto sp1 = std::make_shared<int>(42);
    wp = sp1;

    std::cout << std::boolalpha;
    std::cout << "before destroy: " << wp.expired() << "\n";
  }

  std::cout << "after destroy: " << wp.expired() << "\n";
}