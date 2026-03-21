#include <iostream>

void show_message(const char* message) {
  std::cout << message << std::endl;
  throw 0;
}

void echo_message() {
  char* buffer = new char[100];

  std::cin.get(buffer, 100);

  try {
    show_message(buffer);
  } catch (...) {
    std::cout << "例外を捕まえました (echo_message)" << std::endl;
    delete[] buffer;

    throw;
  }

  delete[] buffer;
}

int main() {
  try {
    echo_message();
  } catch (int e) {
    std::cout << "int型の例外を捕まえました (main)" << std::endl;
  } catch (...) {
    std::cout << "例外を捕まえました (main)" << std::endl;
  }
}
