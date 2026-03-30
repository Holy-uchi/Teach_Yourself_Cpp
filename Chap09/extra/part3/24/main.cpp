decltype(auto) f() {
  int x = 10;
  return x; // return (x)とするとダングリング参照になる
  // 参照は必要ないので、auto f();でいい
}

int main() { f(); }
