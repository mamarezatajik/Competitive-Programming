#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;
typedef pair<pll, ll>       plll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e3 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, c;
ll a[maxN], vis[maxN], dist[maxN][maxN];
vector<pair<ll, pll>> adj[maxN];

void Dijkstra(ll src) {
    fill(vis, vis + n + 1, false);
    fill(dist, dist + n + 1, inf);
    dist[src][src] = 0;

    priority_queue<plll, vector<plll>, greater<plll>> pq;
    pq.push({{0, 0}, src});

    while (!pq.empty()) {
        auto [tmp, u] = pq.top();
        auto [ul, uc] = tmp;
        pq.pop();
        if (vis[u]) {
            continue;
        }

        for (auto [v, tmp]: adj[u]) {
            auto [l, c] = tmp;

            if (dist[u][v] > dist[u][u] + l) {
                dist[u][v] = dist[u][u] + l;
                pq.push({{dist[u][v], uc + c}, v});
            }
        }
    }

}


ll _main() {
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        cin >> u >> v >> l >> c;
        adj[u].push_back({v, {l, c}});
        adj[v].push_back({u, {l, c}});
    }

    for (ll i = 1; i <= n; i++) {
        Dijkstra(i);
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}