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
const ll sqt  = 330  + 1;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, cnt = 1;
vector<pll> adj[maxN];
int res[maxN], add[maxN], start[maxN], finish[maxN], par[maxN][sqt + 2];

bool isAnc(ll u, ll v) {
    return (start[u] <= start[v] && finish[v] <= finish[u]);
}

ll lca(ll u, ll v) {
    if (isAnc(u, v)) {
        return u;
    }
    if (isAnc(v, u)) {
        return v;
    }

    while (par[u][sqt] != 0 && !isAnc(par[u][sqt], v)) {
        u = par[u][sqt];
    }

    while (!isAnc(u, v)) {
        u = par[u][1];
    }
    return u;
}

void dfs_stfin(ll node, ll parent) {
    start[node] = cnt++;
    par[node][1] = parent;
    for (ll i = 2; i <= sqt; i++) {
        par[node][i] = par[parent][i - 1];
    }

    for (auto [child, id]: adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs_stfin(child, node);
    }

    finish[node] = cnt++;
    return;
}

ll dfs(ll node, ll parent) {
    ll to_add = add[node], child_add;
    for (auto [child, id]: adj[node]) {
        if (child == parent) {
            continue;
        }
        child_add = dfs(child, node);
        res[id] += child_add;
        to_add += child_add;
    }
    return to_add;
}

ll _main() {
    cin >> n;

    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dfs_stfin(1, 0);

    cin >> k;
    for (ll i = 0; i < k; i++) {
        cin >> u >> v;
        add[u]++;
        add[v]++;
        add[lca(u, v)] -= 2;
    }

    dfs(1, 0);
    for (ll i = 1; i < n; i++) {
        cout << res[i] << " ";
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