#include <concepts>
#include <iostream>

struct ConsolePolicy {
  template <typename T>
  static void log(const T& x) {
    std::cout << x << "\n";
  }
};

template <typename P, typename T>
concept LogPolicy = requires(T x) {
  { P::log(x) } -> std::same_as<void>;
};

template <typename T, typename Policy>
  requires LogPolicy<Policy, T>
class Logger {
public:
  void log(const T& x) { Policy::log(x); }
};

int main_() {
  Logger<int, ConsolePolicy> li;
  li.log(42);
  return 0;
}
