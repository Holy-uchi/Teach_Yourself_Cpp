# 第9章 placement new と手動ライフタイム（4問）

---

## 第54問 placement new による既存メモリへの構築

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <new>
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

* `Tracer` 1個分の生メモリ領域を確保せよ
* その領域に placement new を使って `Tracer("A")` を構築せよ
* 構築後に `name` を標準出力せよ
* 最後に、適切な方法で `Tracer` を破棄し、生メモリも解放せよ

【制約】

* 通常の `new Tracer(...)` は使用禁止
* placement new を使うこと
* オブジェクト破棄とメモリ解放を分けて書くこと
* `delete` による破棄は禁止
* `std::make_unique` / `std::unique_ptr` は使用禁止

【確認ポイント】

* `"construct: A"` が出力されること
* 構築後に `name` が `"A"` として読めること
* `"destruct: A"` が1回だけ出力されること
* オブジェクト構築とメモリ確保が別操作であることを理解していること

【この問題の主眼】

* placement new は「確保済みメモリ上にオブジェクトを構築する」仕組みであることを理解する
* メモリ確保とオブジェクト生成は別概念であることを理解する

---

## 第55問 明示的デストラクタ呼び出しと破棄責務

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <new>
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

* placement new により `Tracer("B")` を構築せよ
* その後、**明示的にデストラクタを呼び出せ**
* デストラクタ呼び出し後、同じオブジェクトを通常の生存中オブジェクトとして扱ってはならないことをコード上で示せ
* 最後に生メモリを解放せよ

【制約】

* オブジェクト破棄には `ptr->~Tracer()` の形を使うこと
* デストラクタ呼び出し後に `ptr->name` へアクセスしてはならない
* `delete` は使用禁止

【確認ポイント】

* `"construct: B"` が出力されること
* `"destruct: B"` が出力されること
* デストラクタ呼び出しが自動ではなく、手動責務であることを理解していること
* 破棄後のオブジェクトへアクセスしてはいけないことを理解していること

【この問題の主眼】

* placement new で構築したオブジェクトは、必要に応じて明示的に破棄する責務が生じることを理解する
* 「破棄されたオブジェクト」はメモリ上にあっても、もう生きたオブジェクトではないことを理解する

---

## 第56問 メモリ確保とオブジェクト構築の分離理解

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <new>
#include <string>

struct Point {
    int x;
    int y;

    Point(int a, int b) : x(a), y(b) {
        std::cout << "construct: " << x << ", " << y << '\n';
    }

    ~Point() {
        std::cout << "destruct: " << x << ", " << y << '\n';
    }
};
```

【要件】

* `Point` 1個分の生メモリを確保した直後の段階では、まだ `Point` オブジェクトが存在しないことを前提にコードを書け
* その後 placement new で `Point(3, 4)` を構築せよ
* 構築後のみ `x`, `y` を読み出して出力せよ
* 最後に明示的に破棄し、メモリを解放せよ

【制約】

* 構築前のメモリに対して `x`, `y` を読もうとしてはならない
* 構築後のみオブジェクトとして扱うこと
* `delete` は使用禁止

【確認ポイント】

* 生メモリ確保だけでは `Point` が存在しないことを理解していること
* placement new 後には `Point` として扱えること
* 構築前後で扱いが変わることを理解していること

【この問題の主眼】

* 「メモリがあること」と「オブジェクトが存在すること」は別であることを理解する
* C++のオブジェクトモデルの基本を、低レイヤ側から理解する

---

## 第57問 同一領域への再構築と未定義動作回避

【問題】
以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
#include <iostream>
#include <new>
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

* 1つの生メモリ領域を確保せよ
* その領域にまず `Tracer("first")` を placement new で構築せよ
* そのオブジェクトを明示的に破棄した後、**同じ領域に** `Tracer("second")` を再構築せよ
* それぞれの構築と破棄が正しく行われることを出力で確認せよ

【制約】

* 再構築前に最初のオブジェクトを必ず破棄すること
* 最初のオブジェクトを破棄せずに上書き構築してはならない
* 最後に2個目のオブジェクトも破棄し、メモリを解放すること
* `delete` は使用禁止

【確認ポイント】

* `"construct: first"` → `"destruct: first"` → `"construct: second"` → `"destruct: second"` の順になること
* 同じ領域を再利用できること
* 破棄せず再構築すると未定義動作の危険があることを理解していること

【この問題の主眼】

* 同一領域への再構築は可能だが、寿命管理を厳密にしないと危険であることを理解する
* オブジェクト寿命の開始と終了を自分で管理する感覚を身につける

