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


ll n, m, k, ctr = 0;
vector<pair<ll, pll>> edges;
vector<pll> adj[maxN];
vector<ll> ans;
set<ll> nodes;


void Dijkstra(ll src) {
    vector<ll> dist (n, inf), vis (n, false);
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

    for (ll i = src + 1; i < n; i++) {
        if (dist[i] != inf) {
            ans.push_back(dist[i]);
        }
    }
}

ll _main() {
    cin >> n >> m >> k;

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }

    sort(all(edges));

    for (ll i = 0; i < m; i++) {
        ll w = edges[i].F;
        auto [u, v] = edges[i].S;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        nodes.insert(u);
        nodes.insert(v);
        ctr++;
        if (ctr == k) {
            break;
        }
    }

    for (ll node: nodes) {
        Dijkstra(node);
    }

    sort(all(ans));

    return cout << ans[k - 1], 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}