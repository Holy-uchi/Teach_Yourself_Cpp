#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;

    ~Node() {
        std::cout << "Node destruct\n";
    }
};

int main() {
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();

    a->next = b;
    b->next = a;

    return 0;
}