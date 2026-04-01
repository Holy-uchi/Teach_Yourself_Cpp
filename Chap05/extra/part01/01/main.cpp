#include <cstddef>
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
  {
    auto p1 = std::make_unique<Tracer>("A");
    std::cout << "ローカルスコープの終わり\n";
  }
  std::cout << "main関数の終わり\n";
}
