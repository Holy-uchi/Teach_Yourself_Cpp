#include <iostream>
#include <string>

class Base {
public:
  virtual std::string name() const;
  virtual std::string most_name() const = 0;
};
std::string Base::name() const { return "Base"; }

class Derived : public Base {
public:
  std::string name() const override;
  std::string most_name() const override;
};
std::string Derived::name() const { return "Derived"; }
std::string Derived::most_name() const { return "most Derived"; }

class MoreDerived : public Derived {
public:
  std::string name() const override;
  std::string most_name() const override;
};
std::string MoreDerived::name() const { return "MoreDerived"; }
std::string MoreDerived::most_name() const { return "most MoreDerived"; }

int main() {
  Derived derived{};
  MoreDerived more_derived{};

  std::cout << derived.name() << std::endl;
  std::cout << derived.most_name() << std::endl;
  std::cout << more_derived.name() << std::endl;
  std::cout << more_derived.most_name() << std::endl;
}
