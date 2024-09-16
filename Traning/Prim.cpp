#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], n, m, vis[maxN], ans;
vector<pll> adj[maxN];

void Prim(ll node) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, node});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) {
            continue;
        }
        ans += d;
        vis[u] = true;
        for (auto [v, w]: adj[u]) {
            if (vis[v]) {
                continue;
            }
            pq.push({w, v});
        }
    }
}


ll _main() {
    cin >> n >> m;

    ll mn = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[mn] > a[i]) {
            mn = i;
        }
    }

    for (ll i = 0; i < n; i++) {
        adj[mn].push_back({i, a[i] + a[mn]});
        adj[i].push_back({mn, a[i] + a[mn]});
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ans = 0;
    Prim(0);

    return cout << ans, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}