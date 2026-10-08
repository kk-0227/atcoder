// ダブリング (各頂点から出る辺がちょうど1本のとき、k回進んだ先を求める)
// 前処理: O(N log K)  クエリ: O(log K)  メモリ: O(N log K)
// 使い方:
//   vector<int> next = {...}; // next[v] : vから1回進んだ先(0-indexed)
//   Doubling d(next, K);      // Kは進む回数の最大値
//   d.jump(v, k);             // vからk回進んだ先 (k <= K)
struct Doubling{
	int LOG;
	vector<vector<int>> table; // table[i][v] : vから2^i回進んだ先
	Doubling(const vector<int>& next, long long max_k = 1000000000000000000LL){
		int N = next.size();
		LOG = 1;
		while((1LL << LOG) <= max_k)LOG++; // 2^LOG > max_k となる最小のLOG
		table.assign(LOG, vector<int>(N));
		table[0] = next; // 1回の移動で行く先
		for(int i = 0; i + 1 < LOG; i++){
			for(int v = 0; v < N; v++){
				table[i + 1][v] = table[i][table[i][v]]; // 2^i回進んだ先から、さらに2^i回進む
			}
		}
	}
	
	int jump(int v, long long k){ // vからk回進んだ先を返す
		for(int i = 0; i < LOG; i++){
			if(k >> i & 1)v = table[i][v]; // kの2進表記で立っているビットの分だけ進む
		}
		return v;
	}
};