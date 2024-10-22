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
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, root = 1;
ll par[maxN][lg + 1], dep[maxN], children[maxN];
vector<ll> adj[maxN];

ll dfs_pre(ll node, ll parent) {
    par[node][0] = parent;
    dep[node] = dep[parent] + 1;
    for (ll i = 1; i <= lg; i++) {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }

    children[node] = 1;
    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }
        children[node] += dfs_pre(child, node);
    }

    return children[node];
}

ll lca(ll u, ll v) {
    for (ll i = lg; i >= 0; i--) {
        if (dep[u] - dep[v] >= (1 << i)) {
            u = par[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (ll i = lg; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

pll mid(ll u, ll h) {
    for (ll i = lg; i >= 0; i--) {
        if (dep[u] - h > (1 << i)) {
            u = par[u][i];
        }
    }
    return {par[u][0], u};
}

ll _main() {
    cin >> n;
    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_pre(root, 0);

    cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        if (dep[u] < dep[v]) {
            swap(u, v);  // u must be deeper than v;
        }
        l = lca(u, v);

        auto [node1, child1] = mid(u, dep[l]);
        auto [node2, child2] = mid(v, dep[l]);
        ll dist = dep[u] - dep[l] + dep[v] - dep[l];

        if (u == v) {
            cout << n;
        }
        else if (dep[u] == dep[v]) {
            cout << (n - children[child1] - children[child2]);
        }
        else if (dist % 2 == 1) {
            cout << 0;
        }
        else {
            auto [node, child] = mid(u, dep[u] - (dist / 2));
            cout << (children[node] - children[child]);
        }
        cout << '\n';
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