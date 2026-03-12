#include <iostream>

class Integer {
public:
  using value_type = int;
  value_type get_value();
  void set_value(value_type new_value);

private:
  value_type value;
};

Integer::value_type Integer::get_value() { return value; }
void Integer::set_value(value_type new_value) { value = new_value; }

int main() {
  Integer i;
  i.set_value(42);

  std::cout << i.get_value() << std::endl;
}
