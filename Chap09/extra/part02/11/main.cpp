template <typename T>
void f(T&& x) {
  static_cast<void>(x);
}

void g(int&& x) { static_cast<void>(x); }

int main() {
  int x = 10;

  f(x); // T&&には左辺値も渡せる
  // g(x);  // 左辺値を渡せない。
  f(10); // 当然右辺値も渡せる
  g(10); // 当然右辺値は渡せる
}
