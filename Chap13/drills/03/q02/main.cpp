#include <ios>
#include <iostream>
#include <string>

int main() {
  std::string str{"Hello, World!"};
  const char* c_str = str.data();

  std::cout << c_str << std::endl;

  bool is_last_null = (c_str[str.length()] == '\0');
  std::cout << "last is null? : " << std::boolalpha << is_last_null
            << std::endl;
}
