#include <fstream>
#include <iostream>

int main() {
  std::ofstream of{"readonly.txt"};

  if (of.is_open()) {
    std::cout << "オープン成功" << std::endl;
  } else {
    std::cout << "オープン失敗" << std::endl;
  }
}
