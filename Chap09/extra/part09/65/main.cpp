#include <concepts>
#include <iostream>
#include <string>

struct ConsolePolicy {
  template <typename T>
  static void log(T x) {
    std::cout << x << "\n";
  }
};

struct TwicePolicy {
  template <typename T>
  static void log(T x) {
    std::cout << x << " " << x << "\n";
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

int main() {
  Logger<int, ConsolePolicy> li;
  li.log(42);

  Logger<std::string, TwicePolicy> str_twice_logger;
  str_twice_logger.log("Hello, world!");
}
