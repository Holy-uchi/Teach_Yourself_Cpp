#include <string>

template <typename T>
concept LessComparable = requires(T a, T b) { a < b; };

template <LessComparable T>
bool comp(T a, T b) {
  return a < b;
}

struct Person {
public:
  std::string name;
};

int main() {
  comp(3, 0);

  Person p1{"Alice"};
  Person p2{"Bob"};
  // comp(p1, p2);
}
