#include <iostream>

int main() {
  std::cout << R"delim(これは生文字列リテラルです。
改行や\を含むことができます。)delim"
            << std::endl;
}
