#include <iostream>

void h(int&) { std::cout << "h(int&)\n"; }

void h(const int&) { std::cout << "h(const int&)\n"; }

void h(int&&) { std::cout << "h(int&&)\n"; }

template <typename T>
void wrapper(T&& x) {
  h(std::forward<T>(x));
}

int main() {
  int x = 10;
  const int cx = 20;

  wrapper(x);  // => h(int&);
  wrapper(cx); // => h(const int&);
  wrapper(30); // => h(int&&);
}
