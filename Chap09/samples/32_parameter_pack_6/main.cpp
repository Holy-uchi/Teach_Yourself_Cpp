#include <iostream>
#include <utility>

void target(int x, const char* s) { std::cout << x << ", " << s << '\n'; }

template <typename... Args>
void call(Args&&... args) {
  target(std::forward<Args>(args)...);
}

int main() { call(42, "hello"); }
