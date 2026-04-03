#include <memory>

class Foo {
public:
    Foo() = default; 
    // ヘッダ内で定義すると、Foo を破棄する側の翻訳単位で
    // unique_ptr<Impl> のデストラクタが必要になる。
    // そのとき Impl が完全型で見えていないとエラーになりうる。
    // つまり Impl の完全定義が「実装側」ではなく
    // 「使う側の翻訳単位」に要求されてしまう。
    ~Foo() = default; 

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};