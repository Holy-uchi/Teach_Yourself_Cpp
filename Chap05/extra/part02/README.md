# 第2章 `unique_ptr` の実務操作とRAII（7問）

---

## 第8問 `get()` が返す“借用ポインタ”の意味と寿命制約

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

void printValue(const int* p) {
    if (p) {
        std::cout << "value: " << *p << '\n';
    }
}
```

【要件】

* `std::unique_ptr<int>` で `42` を管理する `p` を作成せよ
* `p.get()` を使って `printValue` に値を渡せ
* `printValue` 呼び出し後も `p` が所有権を保持していることを確認するため、`*p` を再度出力せよ

【制約】

* `get()` を使うこと
* `release()` を使ってはならない
* 生ポインタを `delete` してはならない

【確認ポイント】

* `printValue` 内で `42` が出力されること
* 呼び出し後も `p` が有効であり、再度 `*p` が参照できること
* `get()` は所有権を移さないことを理解していること

【この問題の主眼】

* `get()` は「借用（borrow）」であり、所有権は移らないことを理解する
* 借用ポインタの寿命は元の `unique_ptr` に依存することを理解する

---

## 第9問 `reset()` による即時破棄と再束縛

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

* `Tracer("A")` を管理する `std::unique_ptr<Tracer> p` を作成せよ
* `p.reset(new Tracer("B"))` を実行せよ
* `"A"` が破棄され、その後 `"B"` が保持されていることを出力で確認せよ
* 最後に `p->name` を出力して `"B"` であることを確認せよ

【制約】

* `reset` を使うこと
* `delete` は使用禁止
* `shared_ptr` は使用禁止

【確認ポイント】

* `"destruct: A"` が `"construct: B"` の前に出ること
* 最終的に `"B"` が保持されていること
* `reset` が「破棄＋再束縛」であることを理解していること

【この問題の主眼】

* `reset()` は現在の所有物を即座に破棄する操作であることを理解する
* 同時に新しい所有対象へ切り替えることができることを理解する

---

## 第10問 `release()` による所有権の放棄とリークリスク

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

struct Tracer {
    Tracer() { std::cout << "construct\n"; }
    ~Tracer() { std::cout << "destruct\n"; }
};
```

【要件】

* `std::unique_ptr<Tracer> p` を作成せよ
* `Tracer* raw = p.release();` を実行せよ
* `p` が空になることを確認せよ
* `raw` を使って `delete raw;` を行い、デストラクタが呼ばれることを確認せよ

【制約】

* `release()` を必ず使うこと
* `release()` 後に `delete` を書かないと不合格とする
* `shared_ptr` は使用禁止

【確認ポイント】

* `release()` 後に `p == nullptr` であること
* `delete raw;` をしない場合、デストラクタが呼ばれない（リークする）ことを理解していること
* `release()` が所有権を完全に手放す操作であること

【この問題の主眼】

* `release()` は非常に危険な操作であることを理解する
* RAIIの外に出ると、手動管理が必要になることを理解する

---

## 第11問 生ポインタAPIへ安全に橋渡しするラッパ設計

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

void legacyProcess(int* p) {
    if (p) {
        *p += 10;
    }
}
```

【要件】

* `std::unique_ptr<int>` を使って `10` を管理せよ
* `get()` を使って `legacyProcess` に渡せ
* 呼び出し後に値が `20` になっていることを出力せよ
* 所有権は `unique_ptr` 側に残っていること

【制約】

* `release()` は使用禁止
* 生ポインタの `delete` は禁止
* `get()` を使うこと

【確認ポイント】

* 呼び出し後に値が `20` になること
* `unique_ptr` が引き続き有効であること
* C APIに渡すときは借用で十分なケースを理解していること

【この問題の主眼】

* 既存の生ポインタAPIと安全に共存する方法を理解する
* 不必要に所有権を手放さない設計を学ぶ

---

## 第12問 メンバとしての `unique_ptr` とクラスの所有責務

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>
#include <string>

struct Resource {
    std::string name;

    Resource(const std::string& n) : name(n) {
        std::cout << "construct: " << name << '\n';
    }

    ~Resource() {
        std::cout << "destruct: " << name << '\n';
    }
};
```

【要件】

* `Resource` を所有するクラス `Owner` を定義せよ
* `Owner` は `std::unique_ptr<Resource>` をメンバとして持つこと
* コンストラクタで `Resource` を生成すること
* `Owner` のインスタンスが破棄されるときに `Resource` も破棄されることを確認せよ

【制約】

* `Resource` はヒープ上に確保すること
* `delete` は使用禁止
* `shared_ptr` は使用禁止

【確認ポイント】

* `Owner` の破棄時に `Resource` のデストラクタが呼ばれること
* 所有責務が `Owner` にあることがコードで明確であること

【この問題の主眼】

* 「誰が所有しているか」をクラス設計で表現する方法を理解する
* `unique_ptr` をメンバに持つ設計が自然であることを理解する

---

## 第13問 基底クラスポインタ経由の安全な多態破棄

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <memory>

struct Base {
    ~Base() {
        std::cout << "Base destruct\n";
    }
};

struct Derived : Base {
    ~Derived() {
        std::cout << "Derived destruct\n";
    }
};
```

【要件】

* `std::unique_ptr<Base>` で `Derived` を管理せよ
* スコープ終了時に `Derived` のデストラクタも呼ばれるようにせよ

【制約】

* `Base` のデストラクタに適切な修正を加えること
* `unique_ptr` は `Base` 型で持つこと

【確認ポイント】

* `"Derived destruct"` が出力されること
* その後 `"Base destruct"` が出ること
* 修正しない場合は `Derived` のデストラクタが呼ばれないことを理解していること

【この問題の主眼】

* 多態で削除する場合、基底クラスに仮想デストラクタが必要であることを理解する
* `unique_ptr` でも多態破棄のルールは同じであることを理解する

---

## 第14問 カスタムデリータで非メモリ資源（FILE*）をRAII化

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <cstdio>
#include <memory>
#include <iostream>
```

【要件】

* `fopen` でファイルを開き、その `FILE*` を `unique_ptr` で管理せよ
* カスタムデリータとして `fclose` を呼ぶようにせよ
* ファイルを開いた後に `"file opened"` を出力せよ
* スコープ終了時に `fclose` が呼ばれることを確認するため、デリータ内で `"file closed"` を出力せよ

【制約】

* `unique_ptr<FILE, ...>` の形でカスタムデリータを指定すること
* 手動で `fclose` を呼んではならない
* `shared_ptr` は使用禁止

【確認ポイント】

* `"file opened"` が出力されること
* スコープ終了時に `"file closed"` が出力されること
* `FILE*` もRAIIで安全に扱えることを理解していること

【この問題の主眼】

* RAIIはメモリだけでなく任意のリソースに適用できることを理解する
* カスタムデリータにより解放処理を差し替えられることを理解する

