#include <exception>
#include <iostream>

class my_exception : public std::exception {
  const char* message;

public:
  explicit my_exception(const char* message);
  const char* what() const noexcept override;
};

my_exception::my_exception(const char* message) : message{message} {}

const char* my_exception::what() const noexcept { return message; }

int main() {

  try {
    throw my_exception{"My Exception"};
  } catch (my_exception& e) {
    std::cout << "what: " << e.what() << std::endl;
  }
}
