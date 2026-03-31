#include <cassert>
#include <string>
#include <utility>

void consume(std::string&& s) {
  static_cast<void>(s);
  //
}
template <typename T>
void wrapper(T&& x) {
  consume(std::move(x)); // ←これはlvalueを渡した時もrvalueにしてしまう。
  // std::forward(x)が適切
}

int main() {
  std::string s = "hello";

  // consume(s);            // コンパイルできない
  consume(std::move(s)); // パターンB
}
