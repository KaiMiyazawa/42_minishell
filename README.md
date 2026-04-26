# minishell

42 Tokyo の課題として実装した、bash の基本機能を再現するシェルです。字句解析、構文解析、実行、内蔵コマンド、環境変数、リダイレクション、パイプ処理をまとめています。

## 概要

- 出力物: `minishell`
- 主要要素: lexer, parser, executer, builtin, signal handling
- 依存: readline

## 対応機能

- `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- パイプ `|`
- リダイレクション `<`, `>`, `>>`
- Here Document `<<`
- 環境変数展開 `$VAR`
- シングル/ダブルクォート処理

## ビルド

```bash
make
make clean
make fclean
make re
```

## 実行

```bash
./minishell
```

## 実装メモ

- `src/lexer*.c` で入力をトークン化
- `src/parser*.c` でコマンド構造を生成
- `src/executer.c` と `src/exec_*.c` で実行制御
- `src/builtin_*.c` で内蔵コマンドを分離
- `src/sighandler.c` でシグナルを処理
