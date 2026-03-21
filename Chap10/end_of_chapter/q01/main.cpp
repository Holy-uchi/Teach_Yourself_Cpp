#include <iostream>

int main() {
  try {
    std::cout << "例外を投げる前" << std::endl;
    throw 0;
    std::cout << "例外を投げた後" << std::endl;
  } catch (int e) {
    std::cout << "int型の例外をキャッチしました: " << e << std::endl;
  }

  std::cout << "main関数終了" << std::endl;
}
