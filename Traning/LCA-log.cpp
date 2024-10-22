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
const ll Log  = 20  +  2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll par[maxN][Log + 1], dep[maxN], add[maxN], res[maxN];
vector<pll> adj[maxN];

void dfs_pre(ll node, ll parent) {
    par[node][0] = parent;
    for (ll i = 1; i <= Log; i++) {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }

    for (auto [child, id]: adj[node]) {
        if (child == parent) {
            continue;
        }
        dep[child] = dep[node] + 1;
        dfs_pre(child, node);
    }
}

ll dfs(ll node, ll parent) {
    ll to_add = add[node], child_add;
    for (auto [child, id]: adj[node]) {
        if (child == parent) {
            continue;
        }
        child_add = dfs(child, node);
        res[id] = child_add;
        to_add += child_add;
    }
    return to_add;
}

ll lca(ll u, ll v) {
    if (dep[u] < dep[v]) {
        swap(u, v); // u is deeper than v;
    }

    for (ll i = Log; i >= 0; i--) {
        if (dep[u] - dep[v] >= (1 << i)) {
            u = par[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (ll i = Log; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

ll _main() {
    cin >> n;
    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dep[1] = 1;
    dfs_pre(1, 0);

    cin >> k;
    for (ll i = 0; i < k; i++) {
        cin >> u >> v;
        add[u]++;
        add[v]++;
        add[lca(u, v)] -= 2;
    }

    dfs(1, 0);
    for (ll i = 1; i < n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
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