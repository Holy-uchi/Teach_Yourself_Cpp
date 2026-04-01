#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Buffer {
  std::array<T, N> data;

public:
  void fill(T value) {
    for (std::size_t i = 0; i < N; ++i) {
      data[i] = value;
    }
  }

  void print_kind() const {
    if constexpr (N <= 8) {
      std::cout << "small buffer\n";
    } else {
      std::cout << "large buffer\n";
    }
  }
};

int main() {
  Buffer<int, 10> buf;
  buf.fill(100);

  buf.print_kind();
}
