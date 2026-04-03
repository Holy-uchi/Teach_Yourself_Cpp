#include <iostream>
#include <memory>
#include <string>

struct Tracer {
  std::string name;

  Tracer(const std::string& n) : name(n) {
    std::cout << "construct: " << name << '\n';
  }

  ~Tracer() { std::cout << "destruct: " << name << '\n'; }
};

int main() {
  auto p1 = std::make_shared<Tracer>("A");

  auto p2 = p1;

  if (p1) {
    std::cout << "p1->name: " << p1->name << "\n";
  }

  if (p2) {
    std::cout << "p2->name: " << p2->name << "\n";
  }

  std::cout << "count: " << p1.use_count() << "\n";
}
