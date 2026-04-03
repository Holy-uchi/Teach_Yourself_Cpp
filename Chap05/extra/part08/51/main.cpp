int main() {}

// ケースAではstd::atomicが向く
// 理由: 操作が明快なため。

// ケースBではstd::mutexが向く
// 理由: atomicでは複数の変数の更新やまとまった処理を守れないため。