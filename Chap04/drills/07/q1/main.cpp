#include <iostream>

void say_hello() { std::cout << "Hello, from global namespace" << std::endl; }

namespace module {
void say_hello() { std::cout << "Hello, from module namespace" << std::endl; }
} // namespace module

int main() {
  say_hello();
  module::say_hello();
}
