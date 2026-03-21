#include <iostream>
#include <string>
#include <utility>

class Logger {
public:
  explicit Logger(std::ostream& os) : out_(os) {}

  template <typename... Ts>
  void info(Ts&&... args) {
    out_ << "[INFO] ";
    write_all(std::forward<Ts>(args)...);
    out_ << '\n';
  }

  template <typename... Ts>
  void warn(Ts&&... args) {
    out_ << "[WARN] ";
    write_all(std::forward<Ts>(args)...);
    out_ << '\n';
  }

private:
  template <typename... Ts>
  void write_all(Ts&&... args) {
    bool first = true;

    auto write_one = [&](auto&& value) {
      if (!first) {
        out_ << " | ";
      }
      out_ << std::forward<decltype(value)>(value);
      first = false;
    };

    (write_one(std::forward<Ts>(args)), ...);
  }

  std::ostream& out_;
};

int main() {
  Logger logger(std::cout);

  std::string user = "alice";
  int id = 42;
  double score = 98.5;

  logger.info("login succeeded", "user=", user, "id=", id);
  logger.warn("score is high", "value=", score);
}
