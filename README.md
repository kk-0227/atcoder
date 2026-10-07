# atcoder

AtCoder の解答コードと、自作ライブラリの一部です。言語は C++ です。

- AtCoder: [encry](https://atcoder.jp/users/encry)(緑 / highest 1138)
- 旧アカウント: [kaitani0227](https://atcoder.jp/users/kaitani0227)
- 2アカウント合計で約1000問を解いています

## 構成

- `lib/`: 自作ライブラリ(データ構造・グラフ・探索・数学)
- `solutions/`: 解答コード

## ライブラリ

各ファイルの先頭に、前提・計算量・使い方をコメントで書いています。

| 名前 | ファイル | 計算量 | 備考 |
|---|---|---|---|
| Union-Find | [union_find.cpp](lib/data_structure/union_find.cpp) | ならし O(α(N)) | 経路圧縮とランク併合。連結成分ごとの要素数・辺数も管理 |
| ダイクストラ法 | [dijkstra.cpp](lib/graph/dijkstra.cpp) | O((V+E) log V) | 辺の重みは0以上 |
| BFS | [bfs.cpp](lib/graph/bfs.cpp) | O(V+E) | 重みなしグラフの最短距離 |
| DFS(グラフ探索) | [dfs.cpp](lib/graph/dfs.cpp) | O(V+E) | 連結成分の個数 |
| ダブリング | [doubling.cpp](lib/graph/doubling.cpp) | 前処理 O(N log K)、クエリ O(log K) | k回進んだ先を求める |
| 組み合わせの列挙 | [enumerate_combinations.cpp](lib/search/enumerate_combinations.cpp) | O(C(n,k)·k) | DFS(バックトラック) |
| エラトステネスの篩 | [eratosthenes.cpp](lib/math/eratosthenes.cpp) | O(n log log n) | n以下の素数判定表 |

## 解いた問題の例

| 問題 | アルゴリズム | 計算量 | コード |
|---|---|---|---|
| [ABC367 E](https://atcoder.jp/contests/abc367/tasks/abc367_e) | ダブリング | O(N log K) | [abc367_e.cpp](solutions/abc367_e.cpp) |
| [ABC376 D](https://atcoder.jp/contests/abc376/tasks/abc376_d) | BFS | O(N+M) | [abc376_d.cpp](solutions/abc376_d.cpp) |


