#include <cstdio>
#include <iostream>
#include <memory>

struct FileCloser {
  void operator()(FILE* fp) {
    fclose(fp);
    std::cout << "file closed\n";
  }
};

int main() {
  std::unique_ptr<FILE, FileCloser> fp{
      fopen("Chap05/extra/part02/14/main.cpp", "r")};

  if (fp) {
    std::cout << "file opened\n";
  } else {
    std::cout << "failed to open file\n";
    return 1;
  }

  std::cout << "file opened\n";
}
