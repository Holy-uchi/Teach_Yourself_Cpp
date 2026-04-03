#include <cstdlib>
#include <iostream>
#include <string>

struct Tracer {
  std::string name;

  Tracer(const std::string& n) : name(n) {
    std::cout << "construct: " << name << '\n';
  }

  ~Tracer() { std::cout << "destruct: " << name << '\n'; }
};

int main() {
  void* mem = std::malloc(sizeof(Tracer));
  Tracer* p = new (mem) Tracer("B");

  p->~Tracer();
  // pはもうTracer*として使ってはいけない

  std::free(mem);
}
