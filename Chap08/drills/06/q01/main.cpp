#include <fstream>
#include <ios>
#include <iostream>

int main() {
  const char arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  std::ofstream out{"tmp.bin", std::ios::binary};

  out.write(arr, 8);

  out.close();

  std::ifstream in{"tmp.bin", std::ios::binary};

  char buffer[8];
  in.read(buffer, 8);

  std::cout << in.gcount() << std::endl;

  bool same = true;
  for (int i = 0; i < 8; i++) {
    if (arr[i] != buffer[i]) {
      same = false;
    }
  }

  std::cout << std::boolalpha << same << std::endl;
}
