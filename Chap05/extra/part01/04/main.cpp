#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

struct Task {
  std::string title;

  Task(const std::string& t) : title(t) {
    std::cout << "construct: " << title << '\n';
  }

  ~Task() { std::cout << "destruct: " << title << '\n'; }
};

void consumeTask(std::unique_ptr<Task> task_ptr) {
  std::cout << "consumeTask start\n";
  std::cout << task_ptr->title << "\n";
  std::cout << "consumeTask end\n";
}

int main() {
  auto ptr = std::make_unique<Task>("Write report");
  consumeTask(std::move(ptr));

  if (ptr == nullptr) {
    std::cout << "ptr is nullptr\n";
  }
}
