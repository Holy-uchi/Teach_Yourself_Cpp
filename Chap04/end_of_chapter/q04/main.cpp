#include <iostream>

namespace library {
namespace module {
namespace submodule {
void say_hello() { std::cout << "Hello, World!" << std::endl; }
} // namespace submodule
} // namespace module
} // namespace library

namespace submod = library::module::submodule;

int main() { submod::say_hello(); }
