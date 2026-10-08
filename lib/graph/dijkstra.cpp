using ll = long long;
const ll INF = 1LL << 60;

struct WEdge{
	int to;   // 行き先
	ll cost;  // 重み
};
using WGraph = vector<vector<WEdge>>;

// ダイクストラ法
// 始点sから全頂点への最短距離を返す。到達できない頂点は INF のまま
// 前提: 辺の重みが0以上(負の辺があるときは使えない)
// 計算量: O((V + E) log V)
// 使い方:
//   WGraph g(N);
//   g[u].push_back({v, cost}); // u→v の辺 (無向グラフなら逆向きも追加)
//   vector<ll> dist = dijkstra(g, s);
vector<ll> dijkstra(const WGraph& g, int s){
	vector<ll> dist(g.size(), INF);
	using P = pair<ll, int>; // (始点からの距離, 頂点)
	priority_queue<P, vector<P>, greater<P>> q;
	dist[s] = 0;
	q.emplace(0, s);
	while(!q.empty()){
		auto [d, v] = q.top();
		q.pop();
		if(dist[v] < d)continue; // すでにもっと短く行けているなら無視
		for(const auto& e : g[v]){
			ll nd = d + e.cost;
			if(nd < dist[e.to]){
				dist[e.to] = nd;
				q.emplace(nd, e.to);
			}
		}
	}
	return dist;
}