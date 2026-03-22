#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::tuple<int, std::string, double> t = {42, std::string{"Alice"}, 3.14};
  const auto& [a, b, c] = t;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
}
