#include <iostream>
#include <memory>

struct Container {
    int value = 42;

    ~Container() {
      std::cout << "destructor\n";
    }
};

int main() {
  auto c_ptr = std::make_shared<Container>();
  std::shared_ptr<int> v_ptr{c_ptr, &c_ptr->value};


  std::cout << "c_ptr.use_count(): " << c_ptr.use_count() << "\n";
  std::cout << "v_ptr.use_count(): " << v_ptr.use_count() << "\n";

  std::cout << "cptr->value: " << c_ptr->value << "\n";
  std::cout << "*v_ptr: " << *v_ptr << "\n";
}