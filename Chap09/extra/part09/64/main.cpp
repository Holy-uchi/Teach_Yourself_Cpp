#include <string>

template <typename T>
struct DefaultValue {
  static_assert(sizeof(T) == 0, "DefaultValue is not defined for this type");
};

template <>
struct DefaultValue<int> {
  static int get() { return 0; }
};

template <>
struct DefaultValue<double> {
  static double get() { return 0.0; }
};

template <>
struct DefaultValue<std::string> {
  static std::string get() { return ""; }
};

template <typename T>
struct Holder {
  T value = DefaultValue<T>::get();
};

int main() {
  Holder<int> ih;

  Holder<double> dh;

  Holder<std::string> sh;
}
