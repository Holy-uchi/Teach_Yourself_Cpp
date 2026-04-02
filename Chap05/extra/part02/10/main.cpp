#include <iostream>
#include <memory>

struct Tracer {
  Tracer() { std::cout << "construct\n"; }
  ~Tracer() { std::cout << "destruct\n"; }
};

int main() {
  auto p = std::make_unique<Tracer>();

  Tracer* raw = p.release();

  if (!p) {
    std::cout << "p is nullptr" << "\n";
  }

  delete raw;
}
