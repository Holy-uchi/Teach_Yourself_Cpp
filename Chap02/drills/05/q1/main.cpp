#include <iostream>

class ClassNameAsLongAsPossibleToPracticeUsingDeclaration {
  int value;

public:
  int get_value();
  void set_value(int new_value);
};

using ClassALAP = ClassNameAsLongAsPossibleToPracticeUsingDeclaration;

int ClassALAP::get_value() { return value; }
void ClassALAP::set_value(int new_value) { value = new_value; }

int main() {
  ClassALAP klass;
  klass.set_value(42);

  std::cout << klass.get_value() << std::endl;
}
