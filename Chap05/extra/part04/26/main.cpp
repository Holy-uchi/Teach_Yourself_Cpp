#include <iostream>
#include <memory>

struct Node {
    // ここを書き換えてよい
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;

    ~Node() {
        std::cout << "Node destruct\n";
    }
};

int main() {
  auto a = std::make_shared<Node>();
  auto b = std::make_shared<Node>();

  a->next = b;
  b->prev = a;

  return 0;
}