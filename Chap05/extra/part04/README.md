# 第4章 `weak_ptr` と非所有参照（5問）

---

## 第22問 `weak_ptr` の役割：非所有参照の導入

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp id="9xw8yq"
#include <iostream>
#include <memory>
#include <string>

struct User {
    std::string name;

    User(const std::string& n) : name(n) {
        std::cout << "construct: " << name << '\n';
    }

    ~User() {
        std::cout << "destruct: " << name << '\n';
    }
};
```

【要件】

* `std::shared_ptr<User> owner` を作成し、`User("Alice")` を管理せよ
* `owner` から `std::weak_ptr<User> observer` を作成せよ
* `observer` は所有権を増やさないことを確認するため、`owner.use_count()` を出力せよ
* `observer` を作成してもカウントが増えないことを確認せよ

【制約】

* `weak_ptr` は `shared_ptr` から生成すること
* `shared_ptr` をコピーしてはならない（observer生成のために）
* `use_count()` を出力すること

【確認ポイント】

* `owner.use_count()` が `1` のままであること
* `weak_ptr` は参照しているが所有していないこと
* `weak_ptr` の生成が寿命に影響を与えないこと

【この問題の主眼】

* `weak_ptr` は「所有しない参照」であることを理解する
* 参照カウントに影響しないという本質を理解する

---

## 第23問 `lock()` による一時的所有取得と失敗分岐

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp id="9h7z7h"
#include <iostream>
#include <memory>
#include <string>

struct Data {
    std::string value;

    Data(const std::string& v) : value(v) {}
};
```

【要件】

* `std::shared_ptr<Data>` を作成し、それを元に `weak_ptr` を生成せよ
* `lock()` を使って一時的に `shared_ptr` を取得せよ
* `lock()` が成功した場合は値を出力せよ
* 元の `shared_ptr` を破棄した後、再度 `lock()` を試みよ
* 失敗した場合 `"expired"` と出力せよ

【制約】

* `lock()` を必ず使うこと
* 生ポインタは使用しないこと

【確認ポイント】

* 生存中は `lock()` が成功すること
* 破棄後は `lock()` が `nullptr` を返すこと
* 分岐が正しく書かれていること

【この問題の主眼】

* `weak_ptr` から安全にアクセスするには `lock()` が必要であることを理解する
* 寿命が保証されていないことを前提にコードを書く感覚を身につける

---

## 第24問 `expired()` と寿命不確実性の扱い

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp id="wxu6xp"
#include <iostream>
#include <memory>
```

【要件】

* `shared_ptr<int>` を作成し、それから `weak_ptr<int>` を作成せよ
* `expired()` を使って寿命をチェックし、結果を出力せよ
* `shared_ptr` を破棄した後、再度 `expired()` を確認せよ
* 結果が変化することを出力で示せ

【制約】

* `expired()` を必ず使うこと
* `lock()` は使用してもよいが必須ではない

【確認ポイント】

* 生存中は `expired() == false`
* 破棄後は `expired() == true`
* 状態が変化することを確認できること

【この問題の主眼】

* `weak_ptr` は常に「無効化される可能性がある参照」であることを理解する
* 事前チェックの書き方を学ぶ

---

## 第25問 循環参照が発生する構造の特定

【問題】
以下のコードにはメモリリークが発生する構造がある。
その原因を特定し、出力結果から説明せよ。

【与えられるもの】

```cpp id="qz2m6c"
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
```

【要件】

* このコードをそのまま実行せよ
* デストラクタが呼ばれないことを確認せよ
* なぜメモリリークが発生するのかを説明せよ

【制約】

* コードは変更しないこと
* 出力結果と構造から説明すること

【確認ポイント】

* `"Node destruct"` が出力されないこと
* `shared_ptr` 同士が互いを保持している構造を理解できること
* 参照カウントが0にならない理由を説明できること

【この問題の主眼】

* 循環参照が `shared_ptr` の根本的な問題であることを理解する
* 「所有しすぎる」ことが問題になるケースを理解する

---

## 第26問 `weak_ptr` による循環参照の解消設計

【問題】
前問のコードを修正し、メモリリークが発生しないようにせよ。

【与えられるもの】

```cpp id="w6uzbk"
#include <iostream>
#include <memory>

struct Node {
    // ここを書き換えてよい
    std::shared_ptr<Node> next;

    ~Node() {
        std::cout << "Node destruct\n";
    }
};
```

【要件】

* 循環参照を解消するように `Node` を修正せよ
* スコープ終了時に `"Node destruct"` が2回出力されるようにせよ
* 構造として循環を保ちつつ、所有関係だけを調整せよ

【制約】

* `weak_ptr` を使用すること
* 構造（a→b→a）は維持すること
* `delete` は使用禁止

【確認ポイント】

* `"Node destruct"` が2回出力されること
* 循環構造自体は維持されていること
* 所有関係だけが変更されていること

【この問題の主眼】

* 循環参照は「構造」ではなく「所有関係」の問題であることを理解する
* `weak_ptr` によって所有と参照を分離できることを理解する

