#include <iostream>
#include <memory>
#include <string>

struct User {
    std::string name;

    User(const std::string& n) : name(n) {
        std::cout << "construct: " << name << '\n';
    }

    ~User() {
        std::cout << "destruct: " << name << '\n';
    }
};

int main() {
  auto owner = std::make_shared<User>("Alice");

  std::weak_ptr<User> observer = owner;

  std::cout << "参照カウント: " << owner.use_count() << "\n";
}