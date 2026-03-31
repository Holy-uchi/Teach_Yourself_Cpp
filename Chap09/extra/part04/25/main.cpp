#include <iostream>

void f(int) { std::cout << "non-template\n"; }

template <typename T>
void f(T) {
  std::cout << "template\n";
}

int main() {
  f(10); // より具体的なオーバーロードが優先される。=> non-template
  //
}
