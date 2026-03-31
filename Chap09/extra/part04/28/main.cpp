template <typename T>
void f(T) {}

// 関数は部分特殊化できない
// template <typename T>
// void f<T*>(T*) {}

template <typename T>
void f(T*) {}

int main() {
  int ft = 42;

  f(ft);
  f(&ft);
}
