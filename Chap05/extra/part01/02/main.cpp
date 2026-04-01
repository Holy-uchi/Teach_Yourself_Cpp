#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

struct Tracer {
  std::string name;

  Tracer(const std::string& n) : name(n) {
    std::cout << "construct: " << name << '\n';
  }

  ~Tracer() { std::cout << "destruct: " << name << '\n'; }
};

int main() {
  auto p1 = std::make_unique<Tracer>("A");
  std::unique_ptr<Tracer> p2;

  p2 = std::move(p1);

  std::cout << (p1 == nullptr) << "\n";
  if (p2 != nullptr) {
    std::cout << p2->name << "\n";
  }
}
