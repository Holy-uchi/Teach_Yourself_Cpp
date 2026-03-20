#include <fstream>
#include <iostream>

int main() {
  std::ifstream in{"Chap08/end_of_chapter/q04/main.cpp"};

  do {
    in.get();
  } while (in.good());
  in.clear();

  std::cout << static_cast<int>(in.tellg()) << std::endl;
}
