#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::tuple<int, double, std::string> t = {42, 3.14159265,
                                            std::string{"Hello, world!"}};

  auto& [a, b, c] = t;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;

  a = 0;

  std::cout << std::get<0>(t) << std::endl;
}
