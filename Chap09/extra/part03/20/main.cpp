int x;
auto get() {
  return (x); // auto戻り値推論では参照が落ちるので、戻り値型はint
  // 参照を返したいならauto&かdecltype(auto)を使う
  // decltypeはxがlvalueかrvalueかが重要だったが、returnの返り値がlvalueかrvalueかは宣言が大事
}

int main() { get(); }
