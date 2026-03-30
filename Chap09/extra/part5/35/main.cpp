// XXX:
#include <type_traits>
template <typename T>
struct RemovePointer {
  using type = T;
};

template <typename T>
struct RemovePointer<T*> {
  using type = T;
};

int main() { static_assert(std::is_same_v<RemovePointer<int*>::type, int>); }
