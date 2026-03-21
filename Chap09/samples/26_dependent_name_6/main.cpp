#include <iostream>
#include <vector>

template <typename T>
struct Wrapper {
  std::vector<T> data;

  template <typename U>
  using rebind = Wrapper<U>;

  template <typename U>
  void add_and_print(U value) {
    std::cout << value << std::endl;
  }
};

template <typename T>
void process(const Wrapper<T>& w) {
  static_cast<void>(w);
  typename Wrapper<T>::template rebind<double> other;
  other.template add_and_print<int>(123);
}

int main() {
  Wrapper<int> w{{1, 2, 3}};
  process(w);
}
