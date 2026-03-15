// CMAKE_SKIP_EXE

#include <iostream>

extern "C" void call_c();
extern "C" void call_cpp() {
  std::cout << "call_cpp" << std::endl;

  call_c();
}
