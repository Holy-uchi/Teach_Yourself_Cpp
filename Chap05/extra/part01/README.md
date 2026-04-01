# 第1章 単一所有の基礎（7問）

---

## 第1問 `unique_ptr` による単一所有とスコープ破棄の確認

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Tracer {
    std::string name;

    Tracer(const std::string& n) : name(n) {
        std::cout << "construct: " << name << '\n';
    }

    ~Tracer() {
        std::cout << "destruct: " << name << '\n';
    }
};
```

【要件】

* `main` 関数の中で、`Tracer("A")` を管理する `std::unique_ptr<Tracer>` を1つ作成せよ
* `unique_ptr` は**ローカルスコープの内側のブロック**で生成すること
* `unique_ptr` 自身に対して `delete` を書いてはならない
* スコープを抜けたときに `Tracer` のデストラクタが自動で呼ばれることを、標準出力で確認できるようにせよ
* `construct: A` のあと、ブロック終了後に `destruct: A` が出力される構成にせよ

【制約】

* `new` は使ってよい
* `delete` は使用禁止
* `shared_ptr` は使用禁止
* `Tracer` の定義は変更しないこと

【確認ポイント】

* コンパイルが通ること
* 実行時に `construct: A` が表示されること
* ブロックを抜けた直後に `destruct: A` が表示されること
* `delete` を直接書かずに破棄できていること

【この問題の主眼】

* `unique_ptr` が「所有者が1人だけいるポインタ」であることを理解すること
* スコープ終了時に自動で破棄される、という RAII の基本感覚を掴むこと

---

## 第2問 コピー不可と `std::move` による所有権移動

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Tracer {
    std::string name;

    Tracer(const std::string& n) : name(n) {
        std::cout << "construct: " << name << '\n';
    }

    ~Tracer() {
        std::cout << "destruct: " << name << '\n';
    }
};
```

【要件】

* `main` 関数の中で、`Tracer("A")` を管理する `std::unique_ptr<Tracer> p1` を作成せよ
* `p1` の所有権を、別の `std::unique_ptr<Tracer> p2` に**移動**せよ
* 移動後に、

  * `p1 == nullptr` であること
  * `p2 != nullptr` であること
    を標準出力で確認できるようにせよ
* `p2` が `A` を所有していることを、`p2->name` を出力して確認せよ

【制約】

* `p1` を `p2` に**コピー**してはならない
* 所有権移動には `std::move` を使うこと
* `shared_ptr` は使用禁止
* `delete` は使用禁止

【確認ポイント】

* `std::move` を使わない代入はコンパイルエラーになることを理解していること
* 実行時に、移動後 `p1` が空であることを確認できること
* 実行時に、`p2` が `"A"` を保持していることを確認できること
* `destruct: A` は最終的に1回だけ表示されること

【この問題の主眼】

* `unique_ptr` はコピーできず、所有権を移すには `std::move` が必要であることを理解すること
* move 後の元オブジェクトは「所有していない状態」になることを確認すること

---

## 第3問 `make_unique` と例外安全な生成

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct User {
    std::string name;
    int age;

    User(const std::string& n, int a) : name(n), age(a) {
        std::cout << "construct: " << name << ", " << age << '\n';
    }

    ~User() {
        std::cout << "destruct: " << name << '\n';
    }
};
```

【要件】

* `main` 関数の中で、`User("Alice", 20)` を管理する `std::unique_ptr<User>` を作成せよ
* オブジェクト生成には `std::make_unique<User>(...)` を使うこと
* 生成した `unique_ptr` を通じて `name` と `age` を標準出力せよ
* `new User(...)` を直接書かずに作成すること

【制約】

* `std::make_unique` を使うこと
* `new` の直接使用は禁止
* `delete` は使用禁止
* `User` の定義は変更しないこと

【確認ポイント】

* `make_unique` を使って `unique_ptr` を生成できていること
* `name` と `age` が正しく出力されること
* スコープ終了時に `destruct: Alice` が表示されること
* `new User(...)` を直接書いていないこと

【この問題の主眼】

* `make_unique` が `unique_ptr` の基本的な生成手段であることに慣れること
* 生の `new` を直接書かずに所有権付きオブジェクトを作る作法を身につけること

---

## 第4問 関数引数へ所有権を移すインターフェース設計

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Task {
    std::string title;

    Task(const std::string& t) : title(t) {
        std::cout << "construct: " << title << '\n';
    }

    ~Task() {
        std::cout << "destruct: " << title << '\n';
    }
};
```

【要件】

* `std::unique_ptr<Task>` を**値渡し**で受け取る関数 `consumeTask` を定義せよ
* `consumeTask` の中で、受け取った `Task` の `title` を標準出力せよ
* `main` 関数内で `Task("Write report")` を `make_unique` で作成し、それを `consumeTask` に渡せ
* 関数呼び出し後、元のポインタが `nullptr` になっていることを標準出力で確認せよ

【制約】

* `consumeTask` の引数型は `std::unique_ptr<Task>` とすること
* 呼び出し側では `std::move` を使って渡すこと
* 参照渡しは禁止
* `shared_ptr` は使用禁止

【確認ポイント】

* 関数に渡した時点で所有権が呼び出し先へ移ること
* 呼び出し後、呼び出し元の `unique_ptr` が空になること
* `Task` の破棄が最終的に1回だけ起こること
* 「所有権を消費する関数」の形として妥当なインターフェースになっていること

【この問題の主眼】

* `unique_ptr` を関数に値渡しすることが、「所有権を引き渡す」という意味を持つことを理解すること
* API設計において、引数型が所有権の意図を表すことを学ぶこと

---

## 第5問 戻り値で所有権を返すパターン

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Config {
    std::string env;

    Config(const std::string& e) : env(e) {
        std::cout << "construct: " << env << '\n';
    }

    ~Config() {
        std::cout << "destruct: " << env << '\n';
    }
};
```

【要件】

* `std::unique_ptr<Config>` を戻り値として返す関数 `createConfig` を定義せよ
* `createConfig` は `"production"` を持つ `Config` を生成して返すこと
* `main` 関数では、その戻り値を `std::unique_ptr<Config>` で受け取り、`env` を標準出力せよ
* 戻り値を生ポインタにしてはならない

【制約】

* `createConfig` の戻り値型は `std::unique_ptr<Config>` とすること
* オブジェクト生成には `std::make_unique` を使うこと
* `delete` は使用禁止
* `Config` の定義は変更しないこと

【確認ポイント】

* 所有権付きオブジェクトを関数から安全に返せていること
* `main` 側で `env == "production"` を確認できること
* スコープ終了時に `destruct: production` が1回だけ表示されること
* 戻り値として `unique_ptr` を返す設計の意味を理解していること

【この問題の主眼】

* `unique_ptr` は「返してはいけないもの」ではなく、むしろ所有権返却のための自然な戻り値であることを理解すること
* 工場関数的なAPIと `unique_ptr` の相性を掴むこと

---

## 第6問 move後オブジェクトの不変条件（null状態）の扱い

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Item {
    std::string name;

    Item(const std::string& n) : name(n) {}
};
```

【要件】

* `Item("Book")` を管理する `std::unique_ptr<Item> p1` を作成せよ
* `p1` の所有権を `p2` に移せ
* move 後に `p1` を直接デリファレンスしてはならない
* move 後の `p1` が空であることを、`if (p1)` または `p1 == nullptr` によって確認し、結果を標準出力せよ
* `p2->name` を出力して、所有権が正しく移ったことを確認せよ

【制約】

* move 後の `p1` に対して `p1->name` のようなアクセスは禁止
* 所有権移動には `std::move` を使うこと
* `shared_ptr` は使用禁止

【確認ポイント】

* move 後の `unique_ptr` は「有効だが空の状態」として扱うべきだと理解していること
* 空かどうかを確認してから使う、という作法が書けていること
* `p2` は正しく `Book` を所有していること

【この問題の主眼】

* move 後の `unique_ptr` は「壊れたオブジェクト」ではなく、「所有物を持っていない有効なオブジェクト」であることを理解すること
* move 後の扱い方に慣れること

---

## 第7問 `unique_ptr<T>` と `unique_ptr<T[]>` の責務差

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
```

【要件】

* `std::unique_ptr<int>` で単一の `int` を管理するコードを書け
* `std::unique_ptr<int[]>` で長さ3の `int` 配列を管理するコードを書け
* 単一オブジェクト側では `*ptr` により値を読み書きし、標準出力せよ
* 配列側では `ptr[i]` により3要素へ値を代入し、順に標準出力せよ
* 単一オブジェクト用と配列用で、アクセス方法が異なることを確認できるようにせよ

【制約】

* 単一オブジェクト用には `std::unique_ptr<int>` を使うこと
* 配列用には `std::unique_ptr<int[]>` を使うこと
* 配列を `std::unique_ptr<int>` で管理してはならない
* `delete` / `delete[]` は直接書かないこと

【確認ポイント】

* 単一オブジェクトでは `*ptr` でアクセスできること
* 配列では `ptr[i]` でアクセスできること
* `unique_ptr<T>` と `unique_ptr<T[]>` は用途が異なることを理解していること
* どちらも手動 `delete` なしで安全に破棄されること

【この問題の主眼】

* `unique_ptr` には単一オブジェクト版と配列版があり、責務と操作方法が異なることを理解すること
* 「とりあえず `unique_ptr<T>`」ではなく、管理対象に応じて型を選ぶ感覚を身につけること

