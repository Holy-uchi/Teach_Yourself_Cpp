#include <memory>

struct B;
struct C;

struct A {
    std::unique_ptr<B> b;
    std::unique_ptr<C> c;
};

struct B {
    C* c = nullptr;   // あるいは std::weak_ptr<C> ではなく非所有参照にしたい
};

struct C {
    B* b = nullptr;   // 同上
};

int main() {}