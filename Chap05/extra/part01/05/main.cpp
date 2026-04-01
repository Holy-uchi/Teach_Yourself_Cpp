#include <iostream>
#include <memory>
#include <string>

struct Config {
  std::string env;

  Config(const std::string& e) : env(e) {
    std::cout << "construct: " << env << '\n';
  }

  ~Config() { std::cout << "destruct: " << env << '\n'; }
};

auto createConfig() {
  auto config_ptr = std::make_unique<Config>("production");
  return config_ptr;
}

int main() {
  auto config_ptr = createConfig();

  std::cout << config_ptr->env << "\n";
}
