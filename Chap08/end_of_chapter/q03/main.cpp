#include <fstream>
#include <iostream>

int main() {
  // 自分自身を開く
  std::ifstream in{"Chap08/end_of_chapter/q03/main.cpp", std::ios::binary};
  char buffer[128];

  in.read(buffer, 100);

  std::cout << in.gcount() << std::endl;
}
