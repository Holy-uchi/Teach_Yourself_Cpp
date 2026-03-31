#include <concepts>
#include <iostream>
#include <ostream>
#include <string>

template <typename T>
concept Printable = requires(std::ostream& os, const T& x) {
  { os << x } -> std::same_as<std::ostream&>;
};

// Box はprint()を実行できる方だけ受け取るべき
template <Printable T>
struct Box {
  T value;

  void print() const { std::cout << value << "\n"; }
};

struct Person {
  std::string name;
};

int main() {
  Box<int> bi{42};

  bi.print();

  // Box<Person> alice{"Alice"}; // Personはconsole出力できない
}
