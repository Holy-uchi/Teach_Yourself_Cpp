#include <type_traits>

int main() {
  static_assert(std::is_same_v<std::remove_cv_t<const int>, int>);
  static_assert(std::is_same_v<std::remove_cv_t<volatile int>, int>);
  static_assert(std::is_same_v<std::remove_cv_t<const volatile int>, int>);
}
