
template <typename T, typename U>
struct Pair {
  T first;
  U second;
};

template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main() {
  Pair p{1, 2.0};
  static_cast<void>(p);
}
