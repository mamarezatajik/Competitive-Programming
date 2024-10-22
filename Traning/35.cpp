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

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y;
ll dist[maxN], vis[maxN], par[maxN];
vector<pll> adj[maxN];

void Dijkstra(ll src) {
    fill(dist, dist + n + 1, inf);
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
            if (dist[v] == dist[u] + w) {
                if (u != n) {
                    par[v] = u;
                }
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v});
                par[v] = u;
            }
        }
        vis[u] = true;
    }
}


ll _main() {
    cin >> n >> m >> k;

    for (ll i = 0; i <= n; i++) {
        par[i] = -1;
    }

    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (ll i = 0; i < k; i++)  {
        u = 0;
        cin >> v >> w;
        v--;
        adj[u].push_back({n, 0});
        adj[n].push_back({v, w});
    }

    Dijkstra(0);
    ll ans = 0;
    for (ll i = 1; i < n; i++) {
        if (par[i] == n) {
            ans++;
        }
    }

    return cout << (k - ans), 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}