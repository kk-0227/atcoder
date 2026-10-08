#include <vector>
#include <queue>
#include <utility>
#include <functional>

using ll = long long;
const ll INF = 1LL << 60;

struct Edge {
    int to;   // 行き先
    ll cost;  // 重み
};
using Graph = std::vector<std::vector<Edge>>;

// ダイクストラ法
// 始点sから全頂点への最短距離を返す。到達できない頂点は INF のまま
// 前提: 辺の重みが0以上(負の辺があるときは使えない)
// 計算量: O((V + E) log V)
std::vector<ll> dijkstra(const Graph& g, int s) {
    std::vector<ll> dist(g.size(), INF);
    using P = std::pair<ll, int>;  // (始点からの距離, 頂点)
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    dist[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        if (dist[v] < d) continue;  // すでにもっと短く行けているなら無視
        for (const auto& e : g[v]) {
            ll nd = d + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                q.emplace(nd, e.to);
            }
        }
    }
    return dist;
}

