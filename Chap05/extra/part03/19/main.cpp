#include <iostream>
#include <memory>

void byValue(std::shared_ptr<int> p) {
    std::cout << "inside byValue: " << p.use_count() << '\n';
}

void byConstRef(const std::shared_ptr<int>& p) {
    std::cout << "inside byConstRef: " << p.use_count() << '\n';
}

int main() {
  auto p = std::make_shared<int>(42);

  std::cout << "byValue呼び出し前: " << p.use_count() << "\n";
  byValue(p);
  std::cout << "byValue呼び出し後: " << p.use_count() << "\n";

  std::cout << "byConstRef呼び出し前: " << p.use_count() << "\n";
  byConstRef(p);
  std::cout << "byConstRef呼び出し後: " << p.use_count() << "\n";
}