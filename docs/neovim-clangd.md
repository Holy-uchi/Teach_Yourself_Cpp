# Neovim + clangd

このリポジトリで C++ を編集するとき、Neovim の LSP と `clangd` を使うと定義ジャンプ・参照検索・ホバーなどが使えます。

## キー割り当て

定義ジャンプは LSP の `vim.lsp.buf.definition()` です。clangd は go-to-definition / declaration / references を提供します。

```lua
vim.keymap.set("n", "gd", vim.lsp.buf.definition, { desc = "Go to definition" })
vim.keymap.set("n", "gD", vim.lsp.buf.declaration, { desc = "Go to declaration" })
vim.keymap.set("n", "gr", vim.lsp.buf.references, { desc = "References" })
vim.keymap.set("n", "gi", vim.lsp.buf.implementation, { desc = "Go to implementation" })
vim.keymap.set("n", "K",  vim.lsp.buf.hover, { desc = "Hover" })
```

| キー | 動作           |
|------|----------------|
| `gd` | 定義へ         |
| `gD` | 宣言へ         |
| `gr` | 参照一覧       |
| `gi` | 実装へ         |
| `K`  | 型・コメント表示 |

## clangd の最小設定

Neovim 0.11 系なら `nvim-lspconfig` で次のように有効にできます。

```lua
require("lspconfig").clangd.setup({})
```

## lazy.nvim でそのまま使う

`nvim-lspconfig` とキーマップをまとめた例です。

```lua
{
  "neovim/nvim-lspconfig",
  config = function()
    local lspconfig = require("lspconfig")

    lspconfig.clangd.setup({})

    vim.keymap.set("n", "gd", vim.lsp.buf.definition, { desc = "Go to definition" })
    vim.keymap.set("n", "gD", vim.lsp.buf.declaration, { desc = "Go to declaration" })
    vim.keymap.set("n", "gr", vim.lsp.buf.references, { desc = "References" })
    vim.keymap.set("n", "gi", vim.lsp.buf.implementation, { desc = "Go to implementation" })
    vim.keymap.set("n", "K", vim.lsp.buf.hover, { desc = "Hover" })
  end,
}
```

## compile_commands.json

C++ でジャンプ精度を出すには、**clangd がビルド情報を読めること**が重要です。  
このリポジトリの CMake では次を有効にしています。

```cmake
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
```

`compile_commands.json` は **ビルドディレクトリ**（例: `build/`）に生成されます。clangd はプロジェクトルート付近の親ディレクトリをたどってこのファイルを探すため、リポジトリルートから次のようにシンボリックリンクを張ると便利です。

```bash
# プロジェクトルートで 1 回だけ
ln -s build/compile_commands.json .
```

先に `cmake -S . -B build` で configure しておいてからリンクを作成してください。

## 動作確認

C++ ファイルを開いた状態で次を実行し、clangd がそのバッファに attach しているか確認します。

```vim
:LspInfo
```

あわせて `:checkhealth vim.lsp` で LSP の状態を確認できます。

## 参考

- [Clangd – Features](https://clangd.llvm.org/features)
- [Neovim LSP](https://neovim.io/doc/user/lsp/)
- [nvim-lspconfig](https://github.com/neovim/nvim-lspconfig)
- [Clangd – Configuration](https://clangd.llvm.org/config)
