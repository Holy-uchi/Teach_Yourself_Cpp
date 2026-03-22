#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual ~Base() {}
};

class DerivedA : public Base {};

class DerivedB : public Base {};

void determine_class(const Base& obj) {
  const std::type_info& obj_type = typeid(obj);

  if (obj_type == typeid(DerivedA)) {
    std::cout << "obj は DerivedA型のインスタンスです" << std::endl;
  } else if (obj_type == typeid(DerivedB)) {
    std::cout << "obj は DerivedB型のインスタンスです" << std::endl;
  } else {
    std::cout << "obj は DerivedAでもDerivedBでもないインスタンスです"
              << std::endl;
  }
}

class DerivedC : public Base {};

int main() {
  DerivedA a;

  determine_class(a);

  DerivedB b;

  determine_class(b);

  DerivedC c;

  determine_class(c);
}
