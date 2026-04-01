#include <iostream>
#include <memory>
#include <string>

struct User {
  std::string name;
  int age;

  User(const std::string& n, int a) : name(n), age(a) {
    std::cout << "construct: " << name << ", " << age << '\n';
  }

  ~User() { std::cout << "destruct: " << name << '\n'; }
};

int main() {
  auto pu = std::make_unique<User>("Alice", 20);
  std::cout << "name: " << pu->name << ", age: " << pu->age << "\n";
}
