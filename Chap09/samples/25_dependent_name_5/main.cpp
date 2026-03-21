#include <iostream>
#include <string>

template <typename T>
struct Box {
  using value_type = T;

  T value;

  template <typename U>
  using rebind = Box<U>;

  template <typename U>
  void print_as(const U& x) const {
    std::cout << x << std::endl;
  }
};

template <typename NewType, typename T>
void convert_and_print(const Box<T>& box) {
  static_cast<void>(box);

  typename Box<T>::template rebind<NewType> new_box{};

  new_box.template print_as<std::string>("converted");
}

int main() {
  Box<int> b{42};
  convert_and_print<double>(b);
}
