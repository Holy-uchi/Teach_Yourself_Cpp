#include <iostream>

class Person {
  std::string name;

public:
  Person();
  ~Person();
};

Person::Person() : name("newbee") {
  std::cout << "コンストラクタ呼び出し" << std::endl;
}
Person::~Person() { std::cout << "デストラクタ呼び出し" << std::endl; }

int main() {
  Person p;
  std::cout << "main関数本体" << std::endl;
}
