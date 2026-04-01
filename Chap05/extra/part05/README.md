# 第5章 スマートポインタの設計落とし穴（7問）

---

## 第27問 `this` から `shared_ptr` を生成してはいけない理由

【問題】
以下のコードには危険な点がある。
問題点を説明し、安全な形に修正せよ。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

struct Foo {
    std::shared_ptr<Foo> getPtr() {
        return std::shared_ptr<Foo>(this); // 問題あり
    }

    ~Foo() {
        std::cout << "destruct\n";
    }
};
```

【要件】

* 上記コードの問題点を説明せよ
* 修正案を提示せよ（実装コードも書くこと）
* 同一オブジェクトに対して複数の `shared_ptr` が生成されないようにせよ

【制約】

* `delete` は使用しないこと
* `shared_ptr` を直接 `this` から生成する形は禁止

【確認ポイント】

* 二重管理（二重delete）の危険を説明できること
* `shared_ptr` は1つの管理ブロックで統一される必要があることを理解していること

【この問題の主眼】

* `this` から `shared_ptr` を作ると管理が分裂することを理解する
* 「shared_ptrはどこから来たか」が重要であることを理解する

---

## 第28問 `enable_shared_from_this` の正しい利用条件

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

struct Foo : std::enable_shared_from_this<Foo> {
    std::shared_ptr<Foo> getPtr() {
        // ここを実装
    }
};
```

【要件】

* `getPtr()` 内で、自分自身を指す `shared_ptr` を安全に取得せよ
* `main` で `make_shared<Foo>()` によって生成し、`getPtr()` を呼び出せ
* 同一オブジェクトを共有していることを `use_count()` で確認せよ

【制約】

* `shared_from_this()` を使うこと
* `new Foo` を直接使わないこと

【確認ポイント】

* `use_count()` が2になること
* 同一管理ブロックを共有していること
* 正しく `enable_shared_from_this` が機能していること

【この問題の主眼】

* `enable_shared_from_this` によって安全に自己参照できることを理解する
* 「管理下にあること」が前提であることを理解する

---

## 第29問 `shared_from_this()` が未管理状態で失敗するケース

【問題】
以下のコードを実行し、何が起きるか説明せよ。
また、安全に動作するように修正せよ。

【与えられるもの】

```cpp
#include <memory>

struct Foo : std::enable_shared_from_this<Foo> {
    std::shared_ptr<Foo> getPtr() {
        return shared_from_this();
    }
};

int main() {
    Foo f;
    auto p = f.getPtr(); // 問題あり
}
```

【要件】

* 実行時に何が起きるか説明せよ
* 正しく動作するコードに修正せよ

【制約】

* `enable_shared_from_this` はそのまま使うこと

【確認ポイント】

* 未管理状態で `shared_from_this()` が例外を投げることを理解していること
* `make_shared` 経由で生成する必要があることを理解していること

【この問題の主眼】

* `shared_from_this()` は「shared_ptrで管理されている前提」でしか使えないことを理解する

---

## 第30問 aliasing constructor の用途と参照範囲の分離

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

struct Container {
    int value = 42;
};
```

【要件】

* `shared_ptr<Container>` を作成せよ
* その内部の `value` を指す `shared_ptr<int>` を aliasing constructor で作成せよ
* 両者が同じ所有権を共有していることを `use_count()` で確認せよ

【制約】

* aliasing constructor を使うこと
* 新たに `int` を確保してはならない

【確認ポイント】

* `shared_ptr<int>` が `Container` の寿命に依存していること
* `use_count()` が同じであること
* ポインタ先と所有対象が異なることを理解していること

【この問題の主眼】

* 「所有する対象」と「参照する対象」を分離できることを理解する
* aliasing constructor の意味を理解する

---

## 第31問 Pimpl イディオムにおける `unique_ptr` の適用

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <memory>

class Widget {
public:
    Widget();
    ~Widget();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
```

【要件】

* `Impl` を定義し、`Widget` のコンストラクタで生成せよ
* デストラクタで正しく破棄されるようにせよ
* `Impl` の定義は `.cpp` 側に書く想定で構わない

【制約】

* `unique_ptr` を使うこと
* 生ポインタは禁止

【確認ポイント】

* `Impl` を前方宣言で扱えること
* `unique_ptr` によって自動破棄されること
* Pimpl構造が成立していること

【この問題の主眼】

* 実務でよく使うPimplと `unique_ptr` の相性を理解する
* 実装隠蔽と所有権が結びつくことを理解する

---

## 第32問 incomplete type とデストラクタ定義位置の制約

【問題】
以下のコードにはコンパイルエラーの原因がある。
原因を説明し、修正せよ。

【与えられるもの】

```cpp
#include <memory>

class Foo {
public:
    Foo() = default;
    ~Foo() = default;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
```

【要件】

* なぜこのコードが問題になるか説明せよ
* 修正方法を提示せよ

【制約】

* `unique_ptr` はそのまま使うこと

【確認ポイント】

* incomplete type とデストラクタの関係を理解していること
* デストラクタの定義位置を外に出す必要があることを説明できること

【この問題の主眼】

* `unique_ptr` は破棄時に完全型が必要であることを理解する
* ヘッダ/実装分離における重要なルールを理解する

---

## 第33問 所有権グラフを読み解く設計問題（多点参照構造）

【問題】
以下の構造に対して、適切なポインタ種別を設計せよ。

【与えられるもの】

```cpp
// AはBとCを所有する
// BとCは互いに参照し合う可能性がある
// BとCはAが破棄されたら一緒に消える
```

【要件】

* A, B, C の各メンバに適切なポインタ型を割り当てよ
* なぜその選択になるか説明せよ

【制約】

* `unique_ptr`, `shared_ptr`, `weak_ptr` のみ使用可能
* 不要な共有所有は禁止

【確認ポイント】

* A→B, A→C が所有関係であること
* B↔C が非所有参照であること
* 循環参照を避けていること

【この問題の主眼】

* 所有権グラフを設計として考える力を身につける
* 「どのポインタを使うか」が設計問題であることを理解する
