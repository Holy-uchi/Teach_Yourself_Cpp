#include <type_traits>
int x = 10;

decltype(auto) get() { return (x); }

int main() { static_assert(std::is_same_v<decltype(get()), int&>); }
