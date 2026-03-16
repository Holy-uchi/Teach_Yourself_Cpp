#include <iostream>
#include <string>

class Person {
  int age;
  std::string name;

public:
  Person() : age(-1), name("default") {
    std::cout << "デフォルトコンストラクタ" << std::endl;
  }

  Person(int age) : age(age), name("default") {
    std::cout << "age指定コンストラクタ" << std::endl;
  }

  ~Person() { std::cout << "デストラクタ" << std::endl; }

  void print_age() const { std::cout << this->age << std::endl; }
};

int main() {
  Person* parr = new Person[5]{Person{1}, Person{2}, Person{3}};

  for (int i = 0; i < 5; i++) {
    parr[i].print_age();
  }

  delete[] parr;
}
