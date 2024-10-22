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


ll a[maxN], vis[maxN], dist[maxN], n, m, dst;
vector<pll> adj[maxN];
set<ll> times[maxN];

void Dijkstra(ll src) {
    fill(dist, dist + n + 1, inf);
    dst = 0;
    while (times[src].count(dst)) {
        dst++;
    }
    dist[src] = dst;
    set<pll> pq;
    pq.insert({dist[src], src});

    while (!pq.empty()) {
        auto [d, u] = (*pq.begin());
        pq.erase(pq.begin());
        if (vis[u]) {
            continue;
        }

        for (auto [v, w]: adj[u]) {
            if (dist[v] > d + w) {
                dst = d + w;
                while (times[v].count(dst)) {
                    dst++;
                }
                pq.erase({dist[v], v});
                pq.insert({ dst, v});
                dist[v] = d + w;
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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (ll i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++) {
            ll t;
            cin >> t;
            times[i].insert(t);
        }
    }

    Dijkstra(1);

    return cout << (dist[n] == inf ? -1 : dist[n]) << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}