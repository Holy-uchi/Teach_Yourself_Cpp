# 第1章 template argument deduction の地図を頭に入れる（8問）

---

## 第1問 配列は値渡しで崩壊する

【問題】

以下の仕様を満たすコードを書け。

【与えられるもの】

```cpp
int arr[3] = {1, 2, 3};
```

【要件】

* 次の関数テンプレートを定義せよ

```cpp
template<typename T>
void f(T x);
```

* `f(arr)` を呼び出したときの `T` の型を `static_assert` で検証せよ
* `x` の型も `decltype` を使って検証せよ

【制約】

* `std::is_same_v` を使うこと
* 期待結果をコメントで明示すること
* 実行時出力ではなくコンパイル時検証にすること

【この問題の主眼】

* 配列は値渡しすると **ポインタに崩壊する**
* `T` と `x` の型が一致しないケースを理解する

---

## 第2問 参照で受けると配列は保持される

【問題】

第1問と同じ入力を使い、以下を確認せよ。

【与えられるもの】

```cpp
int arr[3] = {1, 2, 3};
```

【要件】

* 次の関数テンプレートを定義せよ

```cpp
template<typename T>
void f(T& x);
```

* `f(arr)` のときの `T` を検証せよ
* 配列長（3）が型に含まれていることを確認せよ

【制約】

* `std::extent_v` を使って配列サイズも検証すること
* 第1問との違いをコメントで説明すること

【この問題の主眼】

* 参照で受けると **配列は崩壊しない**
* `T = int[3]` になる感覚を掴む

---

## 第3問 const はどこで落ちるのか

【問題】

以下の挙動をすべて検証せよ。

【与えられるもの】

```cpp
const int x = 42;
```

【要件】

次の3つの関数を用意し、それぞれで `T` を検証せよ。

```cpp
template<typename T> void f1(T x);
template<typename T> void f2(T& x);
template<typename T> void f3(const T& x);
```

* `f1(x)` の `T`
* `f2(x)` の `T`
* `f3(x)` の `T`

をすべて `static_assert` で確認せよ

【制約】

* 「constが落ちる／保持される理由」をコメントで説明すること

【この問題の主眼】

* 値渡しでは top-level const は落ちる
* 参照では保持される
* `const T&` の T は「非const」であることに気づく

---

## 第4問 T / T& / const T& / T&& の比較

【問題】

同一入力に対して、推論結果の違いを比較せよ。

【与えられるもの】

```cpp
int x = 10;
const int cx = 20;
```

【要件】

以下の4つをそれぞれ呼び出し、`T` を検証せよ。

```cpp
template<typename T> void f1(T x);
template<typename T> void f2(T& x);
template<typename T> void f3(const T& x);
template<typename T> void f4(T&& x);
```

* `x` を渡した場合
* `cx` を渡した場合

それぞれで `T` がどうなるか比較せよ

【制約】

* 結果を表形式コメントで整理すること

【この問題の主眼】

* 推論は「宣言側」ではなく「引数側との関係」で決まる
* `T&&` は forwarding reference になりうる

---

## 第5問 配列・ポインタ・関数の推論差

【問題】

以下のケースを比較せよ。

【与えられるもの】

```cpp
int arr[3] = {1,2,3};

int foo(int) { return 0; }
```

【要件】

次の関数で `T` をそれぞれ検証せよ

```cpp
template<typename T>
void f(T x);
```

* `f(arr)`
* `f(&arr[0])`
* `f(foo)`

【制約】

* 配列・ポインタ・関数それぞれで `T` がどうなるか説明を書くこと

【この問題の主眼】

* 配列 → ポインタ
* 関数 → 関数ポインタ
* という崩壊ルールを統一的に理解する

---

## 第6問 auto と template の推論の違い

【問題】

次のケースを比較せよ。

【与えられるもの】

```cpp
const int x = 42;
int arr[3] = {1,2,3};
```

【要件】

以下をそれぞれ `static_assert` で検証せよ

* `auto a = x;`
* `auto& b = x;`
* `auto c = arr;`
* template関数に渡したときの `T`

```cpp
template<typename T>
void f(T x);
```

【制約】

* `auto` と template で「似ている点」と「違う点」をコメントで整理すること

【この問題の主眼】

* `auto` 推論は template 推論に似ているが完全一致ではない
* 特に配列と参照でズレる

---

## 第7問 braced-init-list が推論を壊す

【問題】

以下のコードを成立させる／させないケースを観察せよ。

【与えられるもの】

```cpp
template<typename T>
void f(T x);
```

【要件】

次の呼び出しがどうなるかを確認せよ

```cpp
f({1,2,3});
```

さらに以下も試せ

```cpp
auto x = {1,2,3};
```

【制約】

* コンパイルエラーになる理由を説明すること
* `std::initializer_list` を明示した場合の挙動も確認すること

【この問題の主眼】

* braced-init-list は「型ではない」
* 推論を壊す特別な存在

---

## 第8問 推論結果を完全に説明できるか（総合問題）

【問題】

以下のコードについて、すべての型を説明せよ。

【与えられるもの】

```cpp
template<typename T>
void f(T&& x) {
    // ここでの T と x の型を検証
}

int arr[3] = {1,2,3};
const int cx = 10;
```

【要件】

次の呼び出しについて、それぞれ

* `T` の型
* `decltype(x)` の型

を `static_assert` で検証せよ

```cpp
f(arr);
f(cx);
f(42);
```

【制約】

* すべてのケースについて

  * 推論の過程
  * なぜその型になるか
    をコメントで説明すること

【この問題の主眼】

* forwarding reference の理解を deduction レベルで説明できるようにする
* 「なんとなく」ではなく「完全に説明できる」状態にする

---

# 第2章 参照性・value category・forwarding を体に入れる（8問）

---

## 第9問 lvalue を `T&&` に渡したときの推論

【問題】

lvalue を forwarding reference に渡したときの推論を検証せよ。

【与えられるもの】

```cpp
int x = 10;
```

【要件】

次の関数を定義し、`f(x)` を呼び出したときの

* `T` の型
* `decltype(x)`（関数内のパラメータ）の型

を `static_assert` で検証せよ

```cpp
template<typename T>
void f(T&& x);
```

【制約】

* `std::is_same_v` を使うこと
* 「なぜ `T` が参照になるのか」をコメントで説明すること

【この問題の主眼】

* lvalue を渡すと `T` は **参照型になる**
* `T&&` は常に rvalue reference ではない

---

## 第10問 rvalue を `T&&` に渡したときの推論

【問題】

rvalue の場合の推論を検証せよ。

【与えられるもの】

```cpp
// なし
```

【要件】

```cpp
f(42);
```

のときの

* `T`
* `decltype(x)`

を検証せよ

【制約】

* 第9問との違いを明確にコメントで書くこと

【この問題の主眼】

* rvalue のときは `T` は非参照になる
* `T&&` はここで初めて「普通の rvalue reference」になる

---

## 第11問 forwarding reference と単なる rvalue reference の違い

【問題】

次の2つの関数の違いを観察せよ。

【与えられるもの】

```cpp
template<typename T>
void f(T&& x); // forwarding reference

void g(int&& x); // 単なる rvalue reference
```

【要件】

次の呼び出しについて、コンパイル可否と挙動を確認せよ

```cpp
int x = 10;

f(x);     // ?
g(x);     // ?
f(10);    // ?
g(10);    // ?
```

【制約】

* 「どれがコンパイルできて、どれができないか」を明示すること
* forwarding reference が成立する条件を書くこと

【この問題の主眼】

* `T&&` は文脈依存で意味が変わる
* **テンプレートの中だけ特別扱いされる**

---

## 第12問 `std::move` を使うべき場面 / 使ってはいけない場面

【問題】

次のコードの挙動を観察せよ。

【与えられるもの】

```cpp
#include <string>
#include <utility>

void consume(std::string&& s) {
    // 何もしない
}
```

【要件】

次の2パターンを比較せよ

```cpp
std::string s = "hello";

consume(s);            // パターンA
consume(std::move(s)); // パターンB
```

さらに

```cpp
template<typename T>
void wrapper(T&& x) {
    consume(std::move(x)); // ←これ
}
```

の問題点を説明せよ

【制約】

* 「なぜ wrapper が危険か」を説明すること

【この問題の主眼】

* `std::move` は「常に使うべきもの」ではない
* lvalue を強制的に rvalue に変換してしまう

---

## 第13問 `std::forward<T>` を使うべき理由

【問題】

perfect forwarding の必要性を体験せよ。

【与えられるもの】

```cpp
#include <iostream>

void g(int& x) {
    std::cout << "lvalue\n";
}

void g(int&& x) {
    std::cout << "rvalue\n";
}
```

【要件】

次の2つの wrapper を比較せよ

```cpp
template<typename T>
void f1(T&& x) {
    g(x); // パターン1
}

template<typename T>
void f2(T&& x) {
    g(std::forward<T>(x)); // パターン2
}
```

次の呼び出しで出力を確認せよ

```cpp
int x = 10;

f1(x);
f1(10);

f2(x);
f2(10);
```

【制約】

* 出力結果を予想してから実行すること
* 違いを説明すること

【この問題の主眼】

* `x` は常に lvalue として扱われる
* `std::forward<T>` が **value category を復元する**

---

## 第14問 wrapper が value category を壊す例

【問題】

wrapper 関数が意味を壊す例を修正せよ。

【与えられるもの】

```cpp
void process(int& x) {
    std::cout << "lvalue\n";
}

void process(int&& x) {
    std::cout << "rvalue\n";
}

template<typename T>
void wrapper(T&& x) {
    process(x); // 問題あり
}
```

【要件】

* `wrapper(10)` が `"rvalue"` を出力するように修正せよ
* `wrapper(x)` は `"lvalue"` を出力すること

【制約】

* 関数シグネチャは変えないこと
* `std::forward` を使うこと

【この問題の主眼】

* wrapper は簡単に意味を壊す
* forwarding は「意味保存」

---

## 第15問 overload 群に forwarding したときの挙動

【問題】

overload 解決と forwarding の関係を観察せよ。

【与えられるもの】

```cpp
#include <iostream>

void h(int&) {
    std::cout << "h(int&)\n";
}

void h(const int&) {
    std::cout << "h(const int&)\n";
}

void h(int&&) {
    std::cout << "h(int&&)\n";
}
```

【要件】

次の wrapper を使って挙動を観察せよ

```cpp
template<typename T>
void wrapper(T&& x) {
    h(std::forward<T>(x));
}
```

以下を試せ

```cpp
int x = 10;
const int cx = 20;

wrapper(x);
wrapper(cx);
wrapper(30);
```

【制約】

* どの overload が呼ばれるかをすべて説明すること

【この問題の主眼】

* forwarding は overload 解決に直結する
* const / reference / value category のすべてが影響する

---

## 第16問 壊れている perfect forwarding の修正

【問題】

以下のコードは「perfect forwardingっぽいが壊れている」。修正せよ。

【与えられるもの】

```cpp
#include <iostream>

void g(int& x) {
    std::cout << "lvalue\n";
}

void g(int&& x) {
    std::cout << "rvalue\n";
}

template<typename T>
void wrapper(T&& x) {
    auto y = std::forward<T>(x); // ←ここが問題
    g(y);
}
```

【要件】

* `wrapper(10)` が `"rvalue"` を出力するように修正せよ
* `wrapper(x)` が `"lvalue"` を出力するようにせよ

【制約】

* `auto` の使い方を見直すこと
* 変数 `y` を使う形は維持してもよい

【この問題の主眼】

* `auto` は参照性を落とす
* forwarding は「途中で値を受けると壊れる」



---

# 第3章 auto / decltype / decltype(auto) の設計感覚（8問）

---

## 第17問 `auto` は参照を落とす

【問題】

次のコードの型をすべて検証せよ。

【与えられるもの】

```cpp
int x = 10;
int& ref = x;
```

【要件】

以下の変数の型を `static_assert` で検証せよ

```cpp
auto a = ref;
auto& b = ref;
```

* `a` の型
* `b` の型

【制約】

* `std::is_same_v` を使うこと
* なぜ `a` が参照でなくなるのか説明すること

【この問題の主眼】

* `auto` は参照性を落とす（decayする）
* 明示的に `&` を付けないと保持されない

---

## 第18問 `decltype(expr)` の基本ルール

【問題】

`decltype` の基本ルールを確認せよ。

【与えられるもの】

```cpp
int x = 10;
const int cx = 20;
```

【要件】

以下の型をそれぞれ検証せよ

```cpp
decltype(x)
decltype(cx)
```

さらに：

```cpp
decltype(x + 0)
```

も検証せよ

【制約】

* 値カテゴリによって型がどう変わるか説明すること

【この問題の主眼】

* `decltype(expr)` は「式の型」をそのまま取る
* 計算式になると参照性が消える

---

## 第19問 変数名 vs 括弧付き式で結果が変わる

【問題】

`decltype` の最重要罠を体験せよ。

【与えられるもの】

```cpp
int x = 10;
```

【要件】

以下の型を比較せよ

```cpp
decltype(x)
decltype((x))
```

【制約】

* 両者の違いをコメントで説明すること
* なぜ `(x)` だと参照になるのか説明すること

【この問題の主眼】

* `decltype(x)` → 宣言型
* `decltype((x))` → 式（lvalue）→ `T&`

👉 ここが理解できていないと全部崩壊する

---

## 第20問 `auto` 戻り値で意図せずコピーする

【問題】

次の関数の問題点を指摘せよ。

【与えられるもの】

```cpp
int x = 10;

auto get() {
    return (x);
}
```

【要件】

* `get()` の戻り値型を確認せよ
* なぜ参照が返らないのか説明せよ

【制約】

* `decltype` と比較して説明すること

【この問題の主眼】

* `auto` は戻り値でも参照を落とす
* `(x)` でも関係なくコピーになる

---

## 第21問 `decltype(auto)` で参照を保持する

【問題】

第20問を修正せよ。

【与えられるもの】

```cpp
int x = 10;
```

【要件】

* `x` への参照を返す関数を書け
* `decltype(auto)` を使うこと
* 戻り値が `int&` になることを検証せよ

【制約】

* `(x)` を返すこと
* `auto` ではなく `decltype(auto)` を使うこと

【この問題の主眼】

* `decltype(auto)` は「式の型をそのまま保持する」
* 参照もそのまま返る

---

## 第22問 accessor 関数で `auto` が危険

【問題】

次のコードの問題を修正せよ。

【与えられるもの】

```cpp
struct S {
    int value;
};

S s{10};

auto get(S& obj) {
    return obj.value;
}
```

【要件】

* `get(s)` の戻り値が参照になるように修正せよ
* 修正前後で挙動の違いを確認せよ

【制約】

* `decltype(auto)` を使うこと
* なぜ `auto` が危険か説明すること

【この問題の主眼】

* accessor でコピーが発生するとバグになる
* `auto` は安全ではない

---

## 第23問 wrapper 関数の戻り値設計

【問題】

forwarding wrapper の戻り値が壊れる例を修正せよ。

【与えられるもの】

```cpp
int x = 10;

int& g() {
    return x;
}

template<typename F>
auto wrapper(F f) {
    return f();
}
```

【要件】

* `wrapper(g)` の戻り値が `int&` になるように修正せよ

【制約】

* `decltype(auto)` を使うこと
* なぜ `auto` だと壊れるか説明すること

【この問題の主眼】

* wrapper は引数だけでなく戻り値も壊す
* forwarding は戻り値にも必要

---

## 第24問 `decltype(auto)` の過剰使用を見抜く

【問題】

次のコードの問題を指摘せよ。

【与えられるもの】

```cpp
decltype(auto) f() {
    int x = 10;
    return x;
}
```

【要件】

* このコードが危険な理由を説明せよ
* 安全な形に修正せよ

【制約】

* lifetime の観点で説明すること

【この問題の主眼】

* `decltype(auto)` は強力だが危険
* ローカル変数参照を返すバグを作りやすい

---


# 第4章 overload resolution と template の衝突を理解する（8問）

---

## 第25問 非テンプレート vs テンプレートの優先順位

【問題】

次のコードでどちらが呼ばれるかを検証せよ。

【与えられるもの】

```cpp
#include <iostream>

void f(int) {
    std::cout << "non-template\n";
}

template<typename T>
void f(T) {
    std::cout << "template\n";
}
```

【要件】

```cpp
f(10);
```

の出力を確認し、理由を説明せよ

【制約】

* overload resolution のルールに基づいて説明すること

【この問題の主眼】

* **非テンプレートはテンプレートより優先される**
* 「より具体的」が勝つ

---

## 第26問 より特殊なテンプレートが選ばれる

【問題】

次の2つのテンプレートのどちらが選ばれるか確認せよ。

【与えられるもの】

```cpp
#include <iostream>

template<typename T>
void f(T) {
    std::cout << "general\n";
}

template<>
void f<int>(int) {
    std::cout << "specialized\n";
}
```

【要件】

```cpp
f(10);
f(3.14);
```

の出力を確認せよ

【制約】

* 「なぜ int のときだけ違うか」を説明すること

【この問題の主眼】

* 明示的特殊化は特定型に対して優先される

---

## 第27問 オーバーロードと特殊化の混同

【問題】

次のコードの問題点を説明せよ。

【与えられるもの】

```cpp
template<typename T>
void f(T) {
    std::cout << "template\n";
}

template<typename T>
void f(T*) {
    std::cout << "pointer\n";
}
```

【要件】

```cpp
int x = 10;
f(&x);
```

の結果を確認し、

* これは「特殊化」なのか「オーバーロード」なのか説明せよ

【制約】

* 両者の違いを明確に言語化すること

【この問題の主眼】

* これは特殊化ではなく **オーバーロード**
* template間でも普通にoverload解決される

---

## 第28問 関数テンプレートは部分特殊化できない

【問題】

次のコードはコンパイルエラーになる。その理由を説明せよ。

【与えられるもの】

```cpp
template<typename T>
void f(T);

template<typename T>
void f<T*>(T*); // エラー
```

【要件】

* なぜエラーになるか説明せよ
* 代替手段を書け

【制約】

* オーバーロードで解決すること

【この問題の主眼】

* 関数テンプレートは部分特殊化できない
* **オーバーロードで表現する**

---

## 第29問 万能テンプレートが既存設計を壊す

【問題】

次のコードの問題を説明せよ。

【与えられるもの】

```cpp
#include <iostream>

void log(int) {
    std::cout << "int\n";
}

template<typename T>
void log(T) {
    std::cout << "generic\n";
}
```

【要件】

```cpp
log(10);
log(3.14);
```

を実行し、

* なぜこの設計が危険か説明せよ

【制約】

* 実務的な観点で説明すること

【この問題の主眼】

* 万能テンプレートは意図しない呼び出しを吸収する
* 拡張性を壊す可能性がある

---

## 第30問 universal reference が overload を食う

【問題】

次のコードの挙動を確認せよ。

【与えられるもの】

```cpp
#include <iostream>

void f(const std::string&) {
    std::cout << "string\n";
}

template<typename T>
void f(T&&) {
    std::cout << "universal\n";
}
```

【要件】

```cpp
std::string s = "hello";
f(s);
```

の出力を確認し、理由を説明せよ

【制約】

* なぜテンプレートが選ばれるのか説明すること

【この問題の主眼】

* universal reference は非常に強く、既存 overload を食う

---

## 第31問 意図しない implicit conversion

【問題】

次のコードの問題を説明せよ。

【与えられるもの】

```cpp
#include <iostream>

void f(double) {
    std::cout << "double\n";
}

template<typename T>
void f(T) {
    std::cout << "template\n";
}
```

【要件】

```cpp
f(10);
```

の出力を確認し、

* なぜ `double` 版が呼ばれないのか説明せよ

【制約】

* implicit conversion の観点で説明すること

【この問題の主眼】

* template は変換なしで一致するため強い
* overload解決は「変換コスト」で決まる

---

## 第32問 テンプレートを書かない方がいい場面

【問題】

次のコードの設計を見直せ。

【与えられるもの】

```cpp
#include <iostream>

template<typename T>
void print(T x) {
    std::cout << x << "\n";
}
```

【要件】

* この関数の問題点を説明せよ
* より良い設計を提案せよ

【制約】

* 「何でもtemplateにする危険性」を説明すること

【この問題の主眼】

* templateは万能ではない
* 制約のないtemplateは設計を壊す


---

# 第5章 specialization / partial specialization の使い分け（8問）

---

## 第33問 クラステンプレートの全特殊化

【問題】

特定型に対して振る舞いを変えよ。

【与えられるもの】

```cpp id="8u3r1k"
#include <iostream>

template<typename T>
struct Printer {
    static void print() {
        std::cout << "general\n";
    }
};
```

【要件】

* `int` のときだけ `"int specialized"` を出力するようにせよ
* 全特殊化を使うこと

【制約】

* オーバーロードは禁止
* 明示的特殊化で書くこと

【この問題の主眼】

* **全特殊化は「特定の型だけ完全に置き換える」手段**

---

## 第34問 クラステンプレートの部分特殊化

【問題】

ポインタ型だけ振る舞いを変えよ。

【与えられるもの】

```cpp id="n1xj2z"
#include <iostream>

template<typename T>
struct TypeName {
    static void print() {
        std::cout << "value\n";
    }
};
```

【要件】

* `T*` のとき `"pointer"` を出力するようにせよ
* 部分特殊化で実装すること

【制約】

* `if constexpr` は使わないこと

【この問題の主眼】

* 部分特殊化は「型パターン」にマッチさせる

---

## 第35問 pointer 用部分特殊化の応用

【問題】

ポインタかどうかで型を変換せよ。

【与えられるもの】

```cpp id="9z6k9o"
template<typename T>
struct RemovePointer {
    using type = T;
};
```

【要件】

* `T*` の場合は `T` を取り出すようにせよ
* `RemovePointer<int*>::type` が `int` になることを確認せよ

【制約】

* 部分特殊化を使うこと

【この問題の主眼】

* type trait の基本パターンを体験する

---

## 第36問 配列用部分特殊化

【問題】

配列型を扱う特殊化を書け。

【与えられるもの】

```cpp id="8yrwz7"
template<typename T>
struct IsArray {
    static constexpr bool value = false;
};
```

【要件】

* `T[N]` の場合だけ `true` にせよ
* `int[3]` で検証せよ

【制約】

* `std::is_array` は使わないこと
* 部分特殊化で実装すること

【この問題の主眼】

* 配列も型パターンとして扱える

---

## 第37問 const / pointer / reference の分岐

【問題】

型の違いで振る舞いを変えよ。

【与えられるもの】

```cpp id="p9d2w1"
template<typename T>
struct Category {
    static constexpr const char* name = "value";
};
```

【要件】

以下を区別せよ：

* `T`
* `T*`
* `const T`
* `T&`

それぞれ異なる文字列を返すようにせよ

【制約】

* 部分特殊化で実装すること
* `if constexpr` 禁止

【この問題の主眼】

* 型の違いを compile-time に分岐できる

---

## 第38問 boolean flag を使った設計

【問題】

テンプレート引数で振る舞いを切り替えよ。

【与えられるもの】

```cpp id="o4lh2r"
template<bool IsFast>
struct Algorithm;
```

【要件】

* `true` のとき `"fast"`
* `false` のとき `"safe"`

を出力するようにせよ

【制約】

* 部分特殊化で実装すること

【この問題の主眼】

* 型だけでなく値でも分岐できる（policyの原型）

---

## 第39問 type trait を自作する

【問題】

簡単な trait を自作せよ。

【与えられるもの】

```cpp id="0q0y1y"
template<typename T>
struct IsPointer {
    static constexpr bool value = false;
};
```

【要件】

* ポインタ型の場合だけ `true` にせよ
* `int*`, `double*`, `int` で検証せよ

【制約】

* 部分特殊化で実装すること
* `std::is_pointer` は使わないこと

【この問題の主眼】

* trait = 「型に関する情報を返すクラス」

---

## 第40問 specialization vs overload の設計判断

【問題】

次の設計を見直せ。

【与えられるもの】

```cpp id="j82e5v"
template<typename T>
struct Printer {
    static void print(T x) {
        std::cout << x << "\n";
    }
};
```

【要件】

* `const char*` の場合だけ特別扱いしたい
* specialization を使うべきか、関数オーバーロードにすべきか検討せよ
* 両方の実装を書き、比較せよ

【制約】

* 「どちらが適切か」を理由付きで説明すること

【この問題の主眼】

* specialization は万能ではない
* **関数なら overload の方が自然なことも多い**


---

# 第6章 traits と型変換ユーティリティを使いこなす（8問）

---

## 第41問 `std::is_same_v` で型を比較する

【問題】

型の一致をコンパイル時に検証せよ。

【与えられるもの】

```cpp id="s2x7a9"
#include <type_traits>
```

【要件】

以下を `static_assert` で検証せよ

```cpp id="zv3j2n"
std::is_same_v<int, int>          // true
std::is_same_v<int, const int>    // false
std::is_same_v<int&, int>         // false
```

【制約】

* `static_assert` のみで検証すること

【この問題の主眼】

* 型は値ではなく「比較可能なメタ情報」
* `const` / 参照は別物

---

## 第42問 `std::remove_reference_t` で参照を剥がす

【問題】

参照を正規化せよ。

【与えられるもの】

```cpp id="9v7c8m"
#include <type_traits>
```

【要件】

以下の型をすべて `int` に変換せよ

```cpp id="l6m4pj"
int&
int&&
```

【制約】

* `std::remove_reference_t` を使うこと
* 結果を `is_same_v` で確認すること

【この問題の主眼】

* forwarding で混ざる参照を剥がす基本操作

---

## 第43問 `std::remove_cv_t` で const / volatile を剥がす

【問題】

cv修飾を正規化せよ。

【与えられるもの】

```cpp id="cm6h3p"
#include <type_traits>
```

【要件】

以下の型を `int` に変換せよ

```cpp id="h3b8w2"
const int
volatile int
const volatile int
```

【制約】

* `remove_cv_t` を使うこと

【この問題の主眼】

* `const` を剥がすことは安全ではないが、型操作としては重要

---

## 第44問 `std::decay_t` の正体を理解する

【問題】

`decay` が何をしているか確認せよ。

【与えられるもの】

```cpp id="4o0nrc"
int arr[3] = {1,2,3};
```

【要件】

以下の型を検証せよ

```cpp id="4n2m4v"
std::decay_t<decltype(arr)>
```

さらに：

```cpp id="2g3fd1"
const int& → ?
```

【制約】

* `remove_reference` と `remove_cv` の組み合わせと比較すること

【この問題の主眼】

* `decay` = 「値渡ししたときの型」
* 配列 → ポインタ、参照除去、cv除去をまとめてやる

---

## 第45問 `std::conditional_t` で型を分岐する

【問題】

条件によって型を切り替えよ。

【与えられるもの】

```cpp id="7pl1mr"
#include <type_traits>
```

【要件】

* `bool` テンプレート引数を受け取り
* `true` のとき `int`
* `false` のとき `double`

になる型を定義せよ

【制約】

* `std::conditional_t` を使うこと

【この問題の主眼】

* 型も条件分岐できる

---

## 第46問 `std::enable_if_t` の基本

【問題】

特定条件のときだけ関数を有効化せよ。

【与えられるもの】

```cpp id="h8m4va"
#include <type_traits>
#include <iostream>
```

【要件】

* 整数型のときだけ呼べる関数を作れ

```cpp id="r4p0n5"
template<typename T>
??? func(T x);
```

* `func(10)` はOK
* `func(3.14)` はコンパイルエラー

【制約】

* `std::enable_if_t` を使うこと
* `std::is_integral_v` を使うこと

【この問題の主眼】

* 「受けてはいけない型」を落とす

---

## 第47問 trait を組み合わせて制約する

【問題】

複合条件で関数を制約せよ。

【与えられるもの】

```cpp id="2y38v0"
#include <type_traits>
```

【要件】

* 「整数型かつ signed」のときだけ有効な関数を作れ

【制約】

* `std::is_integral_v`
* `std::is_signed_v`

を組み合わせること

【この問題の主眼】

* trait は組み合わせて使う

---

## 第48問 trait ベースで API を分岐する

【問題】

型に応じて処理を変えよ。

【与えられるもの】

```cpp id="v3z2pn"
#include <iostream>
#include <type_traits>
```

【要件】

* 整数型なら `"int"`
* 浮動小数点なら `"float"`

を出力する関数を作れ

【制約】

* `if constexpr` を使うこと
* trait を使って分岐すること

【この問題の主眼】

* 型に応じた分岐は runtime ではなく compile-time でやる


---

# 第7章 SFINAE と enable_if を使って危険な一般化を抑える（8問）

---

## 第49問 特定の型だけ有効にする

【問題】

`int` のときだけ呼べる関数を作れ。

【与えられるもの】

```cpp id="d8f2q1"
#include <type_traits>
#include <iostream>
```

【要件】

```cpp id="6b0y9l"
template<typename T>
void f(T x);
```

を定義し、

* `f(10)` はOK
* `f(3.14)` はコンパイルエラー

にせよ

【制約】

* `std::enable_if_t`
* `std::is_same_v`

を使うこと

【この問題の主眼】

* SFINAEは「特定型を許可する」基本形

---

## 第50問 算術型だけ許可する

【問題】

数値型だけ受け付ける関数を作れ。

【与えられるもの】

```cpp id="z6mwf5"
#include <type_traits>
```

【要件】

* `int`, `double` はOK
* `std::string` はNG

にせよ

【制約】

* `std::is_arithmetic_v` を使うこと

【この問題の主眼】

* 実務では「カテゴリ」で制約する

---

## 第51問 メンバ関数の有無で分岐（入口）

【問題】

あるメンバ関数を持つ型だけ受け付けよ。

【与えられるもの】

```cpp id="91bxrb"
struct A {
    void foo() {}
};

struct B {};
```

【要件】

* `foo()` を持つ型だけ通す関数を作れ
* `A` はOK、`B` はNG

【制約】

* `decltype` と `std::declval` を使うこと

【この問題の主眼】

* 「存在するかどうか」で分岐するのがSFINAEの本質

---

## 第52問 戻り値位置の enable_if

【問題】

戻り値型で制約をかけよ。

【与えられるもの】

```cpp id="9tygzt"
#include <type_traits>
```

【要件】

```cpp id="4t4r9h"
template<typename T>
??? f(T x);
```

* 整数型のときだけ関数が存在するようにせよ

【制約】

* 戻り値に `enable_if_t` を使うこと

【この問題の主眼】

* enable_if は「どこに書くか」で意味が変わる

---

## 第53問 テンプレート引数位置の enable_if

【問題】

テンプレート引数で制約をかけよ。

【与えられるもの】

```cpp id="px4p0c"
#include <type_traits>
```

【要件】

```cpp id="i1ep3m"
template<typename T, typename = ???>
void f(T x);
```

* 浮動小数点型だけ許可せよ

【制約】

* デフォルトテンプレート引数で `enable_if` を使うこと

【この問題の主眼】

* この書き方が実務で一番よく使われる

---

## 第54問 非型テンプレート引数経由の enable_if

【問題】

別の書き方で制約をかけよ。

【与えられるもの】

```cpp id="z2q0e4"
#include <type_traits>
```

【要件】

```cpp id="q08mwt"
template<typename T, std::enable_if_t<条件, int> = 0>
void f(T x);
```

の形で、

* 整数型だけ許可せよ

【制約】

* 非型テンプレート引数を使うこと

【この問題の主眼】

* SFINAEは複数の書き方がある
* 書き方によって可読性が変わる

---

## 第55問 overload + SFINAE の分岐

【問題】

SFINAEで関数を分岐せよ。

【与えられるもの】

```cpp id="7zmr2o"
#include <iostream>
#include <type_traits>
```

【要件】

* 整数型 → `"int"`
* 浮動小数点 → `"float"`

を出力する2つの関数を作れ

【制約】

* overload + enable_if で分岐すること
* `if constexpr` 禁止

【この問題の主眼】

* SFINAEは「関数を消す」ことで分岐する

---

## 第56問 エラーメッセージを改善する

【問題】

次のコードは「通るが使いづらい」。改善せよ。

【与えられるもの】

```cpp id="ptlf0n"
template<typename T>
void f(T x) {
    x.foo(); // fooがないと爆発
}
```

【要件】

* `foo()` を持つ型だけ許可するように修正せよ
* エラーメッセージが分かりやすくなるようにせよ

【制約】

* SFINAEで制約すること
* Conceptsはまだ使わないこと

【この問題の主眼】

* SFINAEはUX改善でもある
* 「遅れて爆発」ではなく「最初から拒否する」

---

# 第8章 C++20 Concepts / requires の入口（6問）

---

## 第57問 標準 concept を使って制約する（`std::integral`）

【問題】

整数型のみ受け付ける関数を concept で定義せよ。

【与えられるもの】

```cpp id="0l0g7k"
#include <concepts>
#include <iostream>
```

【要件】

```cpp id="n7c1j9"
void f(??? x);
```

* `int` はOK
* `double` はコンパイルエラー

にせよ

【制約】

* `std::integral` を使うこと
* `enable_if` は使わないこと

【この問題の主眼】

* **制約を“名前付き”で書ける**
* 読むだけで意図が分かる

---

## 第58問 `requires` で簡単な制約を書く

【問題】

「加算できる型」だけ受け付ける関数を作れ。

【与えられるもの】

```cpp id="1b9r6p"
#include <concepts>
```

【要件】

```cpp id="o9s2m0"
template<typename T>
requires ???
T add(T a, T b);
```

* `a + b` が成立する型のみ許可せよ

【制約】

* `requires` 式を使うこと

【この問題の主眼】

* conceptを自作しなくても、その場で制約を書ける

---

## 第59問 `enable_if` と concept の比較

【問題】

同じ制約を2通りで書け。

【与えられるもの】

```cpp id="6x1u9t"
#include <type_traits>
#include <concepts>
```

【要件】

* 「整数型のみ許可する関数」を

① `enable_if` 版
② concept 版

の両方で実装せよ

【制約】

* 両者の可読性の違いをコメントで説明すること

【この問題の主眼】

* concept は SFINAE の上位互換ではなく「読みやすい表現」

---

## 第60問 「加算可能」concept を作る

【問題】

独自 concept を定義せよ。

【与えられるもの】

```cpp id="w2r4dy"
#include <concepts>
```

【要件】

* `a + b` が成立する型を `Addable` と定義せよ

```cpp id="f2r7zh"
template<typename T>
concept Addable = ???;
```

* `Addable` を使った関数を作れ

【制約】

* `requires` を使うこと

【この問題の主眼】

* concept = 「型の性質を名前にする」

---

## 第61問 「比較可能」concept を作る

【問題】

比較演算が可能な型を定義せよ。

【与えられるもの】

```cpp id="w8d7zn"
#include <concepts>
```

【要件】

* `<` が使える型を `LessComparable` として定義せよ
* それを使って関数を制約せよ

【制約】

* `requires (a < b)` を使うこと

【この問題の主眼】

* concept は「インターフェースの宣言」

---

## 第62問 制約付き overload の読み分け

【問題】

次のコードの挙動を説明せよ。

【与えられるもの】

```cpp id="g9r3pb"
#include <iostream>
#include <concepts>

template<std::integral T>
void f(T) {
    std::cout << "integral\n";
}

template<std::floating_point T>
void f(T) {
    std::cout << "floating\n";
}
```

【要件】

```cpp id="7c1i4m"
f(10);
f(3.14);
```

の出力を説明せよ

さらに：

```cpp id="1h4c9r"
f(true);
```

の挙動も説明せよ

【制約】

* overload resolution と concept の関係を説明すること

【この問題の主眼】

* concept は overload 解決に統合される
* SFINAEより直感的に読める

---

# 第9章 クラステンプレートの実務設計（6問）

---

## 第63問 small utility class を設計する（意味のある型）

【問題】

単なる `Pair<T, U>` ではなく、「意味のある型」を設計せよ。

【与えられるもの】

```cpp id="h1v3xq"
// なし
```

【要件】

* `MinMax<T>` というクラスを作れ
* 2つの値を保持し、「小さい方」と「大きい方」を保証すること
* コンストラクタで順序を正規化すること

例：

```cpp id="5q8wzt"
MinMax<int> m(10, 3);
// 内部は (3, 10) になる
```

【制約】

* `T` は `<` が使える型とする（concept使ってもOK）
* メンバ関数で `min()` / `max()` を提供すること

【この問題の主眼】

* 型は「データ構造」ではなく「不変条件を持つ抽象」

---

## 第64問 型に依存するデフォルト値戦略

【問題】

型によってデフォルト値を変える設計をせよ。

【与えられるもの】

```cpp id="2o9z9t"
template<typename T>
struct DefaultValue;
```

【要件】

* `int` → `0`
* `double` → `0.0`
* `std::string` → `""`

を返すようにせよ

さらに：

```cpp id="i3q7o1"
template<typename T>
struct Holder {
    T value;
};
```

にデフォルト値を注入せよ

【制約】

* 特殊化を使うこと

【この問題の主眼】

* 型ごとの振る舞いを分離する
* デフォルト戦略を外に出す設計

---

## 第65問 policy class を注入する設計

【問題】

振る舞いを外部から注入せよ。

【与えられるもの】

```cpp id="z7k9b3"
#include <iostream>
```

【要件】

* `Logger<T, Policy>` を作れ
* `Policy` によってログ方法が変わるようにせよ

例：

```cpp id="d5k2l9"
struct ConsolePolicy {
    static void log(int x) {
        std::cout << x << "\n";
    }
};
```

【制約】

* 継承ではなくテンプレート引数で注入すること

【この問題の主眼】

* policy = 振る舞いの差し替えポイント
* 継承より安全で静的

---

## 第66問 CRTP の入口

【問題】

CRTP を使って共通処理を実装せよ。

【与えられるもの】

```cpp id="n8w3x0"
#include <iostream>
```

【要件】

* `Base<Derived>` を作れ
* `Derived` に `impl()` を実装させる
* `Base` 側で `interface()` を提供する

```cpp id="m4z9q1"
struct A : Base<A> {
    void impl();
};
```

【制約】

* `static_cast<Derived*>(this)` を使うこと

【この問題の主眼】

* CRTP = 静的ポリモーフィズム
* 仮想関数を使わない多態性

---

## 第67問 non-type template parameter（固定長ラッパ）

【問題】

サイズを型として持つクラスを作れ。

【与えられるもの】

```cpp id="t3l2c8"
#include <array>
```

【要件】

* `FixedArray<T, N>` を作れ
* 内部に `std::array<T, N>` を持つ
* サイズ `N` をコンパイル時に保持する

【制約】

* `N` は non-type template parameter
* `size()` を提供すること

【この問題の主眼】

* 値も型の一部になる
* サイズが設計に組み込まれる

---

## 第68問 過剰一般化の修正

【問題】

次の設計の問題を修正せよ。

【与えられるもの】

```cpp id="k4w8r2"
template<typename T>
struct Box {
    T value;

    void print() {
        std::cout << value << "\n";
    }
};
```

【要件】

* この設計の問題点を指摘せよ
* 改善案を提示せよ

【制約】

* concept / SFINAE / policy いずれかで改善すること

【この問題の主眼】

* 「何でも受ける」は設計として弱い
* 制約 or 分離が必要


---

# 第10章 CTAD・non-type template parameter・現代的template実務（6問）

---

## 第69問 CTAD が効く / 効かないケース

【問題】

クラステンプレートの型推論の挙動を観察せよ。

【与えられるもの】

```cpp id="c3d9q2"
#include <utility>
```

【要件】

以下をコンパイルし、型を確認せよ

```cpp id="r6z8t1"
std::pair p(1, 2);      // ?
std::pair p2(1, 2.0);   // ?
```

さらに、自作クラスで同様のことを試せ

```cpp id="p9x2f7"
template<typename T, typename U>
struct Pair {
    T first;
    U second;
};
```

```cpp id="q2m8r5"
Pair p(1, 2); // どうなる？
```

【制約】

* なぜ標準の `pair` は推論できて、自作はできないのか説明すること

【この問題の主眼】

* CTADは「勝手に効く」ものではない
* deduction guide が裏で働いている

---

## 第70問 deduction guide の入口

【問題】

自作クラスに CTAD を導入せよ。

【与えられるもの】

```cpp id="z4w1x8"
template<typename T, typename U>
struct Pair {
    T first;
    U second;
};
```

【要件】

```cpp id="m5n3k7"
Pair p(1, 2.0);
```

が動くようにせよ

【制約】

* deduction guide を書くこと

【この問題の主眼】

* CTADは「定義するもの」
* 推論ルールを自分で設計できる

---

## 第71問 `std::array<T, N>` 的思考

【問題】

サイズが型の一部である設計を理解せよ。

【与えられるもの】

```cpp id="h7q2l9"
#include <array>
```

【要件】

以下を確認せよ

```cpp id="v8m4k1"
std::array<int, 3> a;
std::array<int, 4> b;
```

* `a` と `b` が別型であることを `static_assert` で確認せよ

さらに：

* サイズが違うと代入できないことも確認せよ

【制約】

* `std::is_same_v` を使うこと

【この問題の主眼】

* 「値（N）」が型の一部になる
* 型安全性が強くなる

---

## 第72問 `template<auto N>` の基礎

【問題】

非型テンプレート引数に auto を使え。

【与えられるもの】

```cpp id="y3c9v6"
// なし
```

【要件】

```cpp id="z1m8p4"
template<auto N>
struct ConstValue {
    static constexpr auto value = N;
};
```

を定義し、

* `ConstValue<10>::value`
* `ConstValue<'a'>::value`

を確認せよ

【制約】

* 型を明示しないこと

【この問題の主眼】

* NTTPは「型に依存しない値」も扱える

---

## 第73問 文字列長をコンパイル時に扱う

【問題】

配列サイズをコンパイル時に取得せよ。

【与えられるもの】

```cpp id="n5z2t1"
template<size_t N>
constexpr size_t length(const char (&)[N]) {
    return N;
}
```

【要件】

```cpp id="k8p3q7"
length("hello");
```

が `6`（終端含む）になることを確認せよ

【制約】

* ポインタではなく配列参照で受けること

【この問題の主眼】

* 配列参照 + NTTP = サイズを保持できる
* decayさせない設計

---

## 第74問 型引数と値引数を組み合わせた設計

【問題】

型と値の両方を使った設計を行え。

【与えられるもの】

```cpp id="r2m4k9"
#include <array>
```

【要件】

* `Buffer<T, N>` を作れ
* 内部に `std::array<T, N>` を持つ
* `fill(value)` で全要素を埋める

さらに：

* `N` に応じて処理を変える設計を考えよ

【制約】

* `N` は non-type template parameter
* 型と値の役割を明確にすること

【この問題の主眼】

* 型（T）と値（N）を組み合わせる設計が現代C++
* 固定サイズ・最適化・安全性に直結する

---
