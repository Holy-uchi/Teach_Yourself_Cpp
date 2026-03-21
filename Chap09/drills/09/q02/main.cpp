#include <iostream>
#include <string>

void print(int arg) { std::cout << "int: " << arg << std::endl; }
void print(std::string arg) {
  std::cout << "std::string: " << arg << std::endl;
}
void print(float arg) { std::cout << "float: " << arg << std::endl; }
void print(double arg) { std::cout << "double: " << arg << std::endl; }

template <typename... Args>
void print_all(Args... args) {
  ((print(args)), ...);
}

int main() { print_all(1, 1.23456f, 3.14159265, "Hello, world!"); }
