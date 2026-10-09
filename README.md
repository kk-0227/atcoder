# atcoder

AtCoder の解答コードと、自作ライブラリの一部です。言語は C++ です。

- AtCoder: [encry](https://atcoder.jp/users/encry)(緑 / highest 1138)
- 旧アカウント: [kaitani0227](https://atcoder.jp/users/kaitani0227)
- 2アカウント合計で約1000問を解いています

## 解説記事(Qiita)

コンテストの問題を、図つきで解説した記事を Qiita に書いています。
問題文の読み解き、制約からの計算量の見積もり、解法の考え方を、問題ごとにまとめています。

- [【C++】ABC409参加記(A〜F)](https://qiita.com/kai_22/items/f55faa2072bdf57fc1cb)(旧アカウント kaitani0227 での参加)

## 構成

- `lib/`: 自作ライブラリ(データ構造・グラフ・数学)
- `solutions/`: 解答コード

## ライブラリ

各ファイルの先頭に、計算量と、必要に応じて前提・使い方をコメントで書いています。
コンテスト用のテンプレートに貼り付けて使う前提のため、`#include` を省いているファイルがあります。
`combination.cpp` は、AtCoder Library の `modint998244353` を `mint` として使います。

| 名前 | アルゴリズム | 計算量 | ファイル |
|---|---|---|---|
| Union-Find | グループ分けと結合を高速で行う | ならし O(α(N)) | [union_find.cpp](lib/data_structure/union_find.cpp) |
| ダイクストラ法 | グラフ上のある点から他の点までの最短経路を高速で計算する | O((V+E) log V) | [dijkstra.cpp](lib/graph/dijkstra.cpp) |
| ダブリング | ある地点と移動先が与えられている時にk回移動した時の到達点を高速で計算する | 前処理 O(N log K)、クエリ O(log K) | [doubling.cpp](lib/graph/doubling.cpp) |
| 二項係数(mod) | 階乗と、その逆元(逆階乗)を前計算することで二項係数(nCr) を高速で求める| 前処理 O(N)、クエリ O(1) | [combination.cpp](lib/math/combination.cpp) |
| エラトステネスの篩 | n以下の素数を高速で列挙する | O(n log log n) | [eratosthenes.cpp](lib/math/eratosthenes.cpp) |

## 解いた問題の例

| 問題 | アルゴリズム | 計算量 | コード / 考え方 |
|---|---|---|---|
| [ABC367 E](https://atcoder.jp/contests/abc367/tasks/abc367_e) | ダブリング | O(N log K) | [コード](solutions/abc367_e.cpp) / [考え方](solutions/abc367_e.md) |
| [AWC0175 D](https://atcoder.jp/contests/awc0175/tasks/awc0175_d) | 二分探索 | O(N log S) | [コード](solutions/awc0175_d.cpp) / [考え方](solutions/awc0175_d.md) |
