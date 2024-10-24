#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll vis[maxN], dist[maxN], n, m, start = 0;
vector<pll> adj[maxN];

void Dijkstra(ll src) {
    fill(dist + 1, dist + n + 1, inf);
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[src], src});

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }

        for (auto [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v});
            }
        }
        vis[u] = true;
    }
}


ll _main() {
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w << 1});
        adj[v].push_back({u, w << 1});
    }

    for (ll v = 1; v <= n; v++) {
        ll w;
        cin >> w;
        adj[start].push_back({v, w});
    }

    Dijkstra(start);

    for (ll i = 1; i <= n; i++) {
        cout << dist[i] << " \0"[i == n];
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}