#include <iostream>

void log(int) { std::cout << "int\n"; }

template <typename T>
void log(T) { // 万能テンプレートは意図しない呼び出しを吸収する。
  // むしろコンパイルエラーになるべき呼び出しも通してしまう。
  std::cout << "generic\n";
}

int main() {
  log(10);
  // log(3.14); // log(int)
  // でも呼べたはずなのにgenericが呼ばれる(その方が安全にマッチするから)
}
