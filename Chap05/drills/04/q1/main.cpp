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
  Person* p1 = new Person{};
  Person* p2 = new Person{20};

  delete p1;
  delete p2;
}
