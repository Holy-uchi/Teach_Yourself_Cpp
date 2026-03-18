#include <iostream>

class Person {
  int age;

public:
  Person() : age(25) {}
  Person(int age) : age(age) {
    std::cout << "Person: コンストラクタ呼び出し" << std::endl;
  }

  ~Person() { std::cout << "Person: デストラクタ呼び出し" << std::endl; }

  void say_age() { std::cout << this->age << std::endl; }
};

class UniquePersonPtr {
  Person* ptr;

public:
  UniquePersonPtr(Person* ptr) : ptr(ptr) {
    std::cout << "UniquePersonPtr: コンストラクタ呼び出し" << std::endl;
  }

  ~UniquePersonPtr() {
    std::cout << "UniquePersonPtr: デストラクタ呼び出し" << std::endl;
    delete this->ptr;
  }

  UniquePersonPtr(const Person&) = delete;

  Person& operator*() const;
  Person* operator->() const;
};

Person& UniquePersonPtr::operator*() const { return *(this->ptr); }
Person* UniquePersonPtr::operator->() const { return this->ptr; }

int main() {
  UniquePersonPtr person_ptr{new Person{20}};
  (*person_ptr).say_age();
  person_ptr->say_age();
}
