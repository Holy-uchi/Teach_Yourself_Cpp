#include <type_traits>

int main() {
  static_assert(std::is_same_v<std::remove_reference_t<int&>, int>);
  static_assert(std::is_same_v<std::remove_reference_t<int&&>, int>);
}
