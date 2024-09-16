#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 1e10 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], dist[maxN];
vector<pll> adj[maxN];

void Dijkstra(ll src, ll n, ll k) {
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[src], src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto [v, w]: adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}


ll _main() {
    ll n, m, k; 
    cin >> n >> m >> k;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        adj[n].push_back({i, a[i]});
        adj[i].push_back({n, a[i]});
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (ll i = 0; i < k; i++) {
        ll src;
        cin >> src;
        src--;

        fill(dist, dist + n + 1, inf);
        Dijkstra(src, n, k);
        for (ll i = 0; i < n; i++) {
            cout << dist[i] << " \n"[i == n - 1];
        }
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