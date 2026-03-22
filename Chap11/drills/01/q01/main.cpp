#include <iostream>
#include <typeinfo>

int main() {
  auto lambda1 = [](int a, int b) { return a + b; };
  auto lambda2 = [](int a, int b) { return a + b; };

  const std::type_info& lambda1_type = typeid(lambda1);
  const std::type_info& lambda2_type = typeid(lambda2);

  if (lambda1_type == lambda2_type) {
    std::cout << "二つのlambda関数は同じ型です" << std::endl;
  } else {
    std::cout << "二つのlambda関数は異なる型です" << std::endl;
  }
}
