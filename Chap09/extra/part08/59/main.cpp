#include <concepts>
#include <iostream>
#include <type_traits>

// enable_ifで書くと、それの置き場所を作るための儀式が増える(戻り値やダミー型パラメータなど)
template <typename T>
std::enable_if_t<std::is_integral_v<T>, void> f(T x) {
  std::cout << ++x;
}

// conceptsでかくとTが何を受け入れるのかを直観的にかける
template <std::integral T>
void g(T x) {
  std::cout << ++x;
}

int main() {
  f(42);

  g(0);
}
