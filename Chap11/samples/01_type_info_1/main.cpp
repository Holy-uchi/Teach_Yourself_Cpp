#include <iostream>
#include <typeinfo>

int main() {
  const std::type_info& int_type = typeid(int);
  const std::type_info& one_type = typeid(1);

  if (int_type == one_type) {
    std::cout << "1はint型です" << std::endl;
  } else {
    std::cout << "1はint型ではありません" << std::endl;
  }

  const std::type_info& str_type = typeid("hoge");

  if (int_type != str_type) {
    std::cout << "\"hoge\"はint型ではありません" << std::endl;
  } else {
    std::cout << "\"hoge\"はint型です" << std::endl;
  }
}
