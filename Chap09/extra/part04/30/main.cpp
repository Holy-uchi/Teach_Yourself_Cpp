#include <iostream>
#include <string>

void f(const std::string&) { std::cout << "string\n"; }

template <typename T>
void f(T&&) {
  std::cout << "universal\n";
}

int main() {
  std::string s = "hello";
  // f(const std::string&)は、constをつけてconst std::string&で受ける必要がある
  // f(T&&)は、std::string&で受けられる。
  // f(T&&)の方がより良く一致するのでf(T&&)が優先される
  f(s);
}
