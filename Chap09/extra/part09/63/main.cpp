#include <iostream>

template <typename T>
  requires requires(T a, T b) { a < b; }
class MinMax {
  T min_;
  T max_;

public:
  MinMax(T a, T b) : min_(b < a ? b : a), max_(b < a ? a : b) {}
  const T& min() const { return this->min_; }
  const T& max() const { return this->max_; }
};

int main() {
  MinMax<int> m(10, 3);
  std::cout << "min: " << m.min() << ", max: " << m.max() << "\n";

  const MinMax<std::string> n("John", "Alice");
  std::cout << "min: " << n.min() << ", max: " << n.max() << "\n";
}
