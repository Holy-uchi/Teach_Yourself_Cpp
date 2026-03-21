#include <exception>
#include <iostream>

class A {
  int value;

public:
  static int count;
  A(int value) : value(value) {
    std::cout << "コンストラクタ呼び出し: " << value << std::endl;
    count++;
    if (count == 5) {
      throw 0;
    }
  }

  ~A() { std::cout << "デストラクタ呼び出し: " << value << std::endl; }
};

int A::count = 0;

int main() {

  try {

    A* arr = new A[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    static_cast<void>(arr);
  } catch (...) {
    std::cout << "例外をキャッチしました" << std::endl;
  }
}
