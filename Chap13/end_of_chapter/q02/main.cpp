#include <iostream>
#include <string>

int main() {
  auto ft_str = std::to_string(42);

  std::cout << ft_str << std::endl;

  auto ft_int = std::stoi(ft_str);

  std::cout << ft_int << std::endl;
}
