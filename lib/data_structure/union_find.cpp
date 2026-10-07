// Union-Find (経路圧縮 + ランクによる併合)
// 計算量: ならし O(α(N))
struct UnionFind{
	vector<int> par, rank, size, edge_count;
	// par[i] : iの親
	// rank[i] : iから一番下までの距離
	// size[i] : iを根とする集合の要素数
	// edge_count[i] : iを根とする集合の辺の数	
	UnionFind(int N) : par(N), rank(N, 0), size(N, 1), edge_count(N, 0){ // 初期化 自分の親は自分自身とする
		for(int i = 0; i < N; i++)par[i] = i;
	}
	
	int root(int x){ // xの根を返す
		if(par[x] == x)return x;
		return par[x] = root(par[x]); // 経路圧縮
	}
	
	bool unite(int x, int y){ // xとyがそれぞれ含まれている二つの木の併合
		int rx = root(x); // それぞれの根を見つける
		int ry = root(y);
		if(rx == ry){// 根が同じ(元から同じ木に属している)ならそのまま
			edge_count[rx]++; // 辺の数を増やす
			return false;
		}
		if(rank[rx] > rank[ry])swap(rx, ry); // 長い方を新たな根とする
		par[rx] = ry; // xの根の親をyの根に繋ぐ
		size[ry] += size[rx];
		edge_count[ry] += edge_count[rx] + 1;
		if(rank[rx] == rank[ry])rank[ry]++;
		return true;
	}
	
	bool same(int x, int y){ // xとyが同じ木ならtrue,違うならfalseを返す
		return root(x) == root(y);
	}
	int get_edge_count(int x) { // xを含む木の辺の数を返す
		return edge_count[root(x)];
	}
  int get_size(int x) { // xを含む木の要素数を返す
		return size[root(x)];
	}
};
