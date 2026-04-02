#include <iostream>
#include <memory>
#include <string>

struct Resource {
  std::string name;

  Resource(const std::string& n) : name(n) {
    std::cout << "construct: " << name << '\n';
  }

  ~Resource() { std::cout << "destruct: " << name << '\n'; }
};

class Owner {
  std::unique_ptr<Resource> resource;

public:
  Owner(const std::string& n) : resource(std::make_unique<Resource>(n)) {
    std::cout << "construct: Owner\n";
  }

  ~Owner() { std::cout << "destruct: Owner\n"; }
};

int main() { Owner o{"A"}; }
