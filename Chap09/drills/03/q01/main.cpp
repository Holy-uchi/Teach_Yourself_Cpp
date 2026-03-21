#include <iostream>
#include <string>

template <typename T>
class Base {
  T value;

public:
  T get_value() const { return this->value; }
  void set_value(T value) { this->value = value; }
  virtual void say_something(T input) {
    std::cout << "Base::say_something(): " << input << std::endl;
  }
};

template <typename T>
class Derived : public Base<T> {
  void say_something(T input) override {
    std::cout << "Derived::say_something(): " << input << std::endl;
  }
};

int main() {
  Derived<std::string> derived;
  derived.set_value("hoge");
  std::cout << derived.get_value() << std::endl;

  Base<std::string>& base = derived;
  base.say_something("hello, world");
}
