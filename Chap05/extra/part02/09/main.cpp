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
  auto p = std::make_unique<Tracer>("A");

  p.reset(new Tracer("B"));

  if (p) {
    std::cout << "p->name: " << p->name << "\n";
  }
}
