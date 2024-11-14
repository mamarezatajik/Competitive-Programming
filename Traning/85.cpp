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
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll dep[maxN];
pll par[maxN][lg + 1];
pll fur[maxN]; // maximum depth of one of its child;
vector<ll> adj[maxN];

void dfs_pre(ll node, ll parent) {
    dep[node] = dep[parent] + 1;
    fur[node] = {0, 0};

    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs_pre(child, node);
        fur[node].S = max(fur[node].S, fur[child].F + 1);
        if (fur[node].F < fur[node].S) {
            swap(fur[node].F, fur[node].S);
        }
    }
}

void dfs_lca(ll node, ll parent) {
    par[node][0] = {fur[parent].F, parent};
    if (fur[parent].F == fur[node].F + 1) {
        par[node][0].F = fur[parent].S;
    }
    if (node == 2) {
        // cout << par[node][0].F << " " << par[node][0].S << endl;
    }
    for (ll i = 1; i <= lg; i++) {
        par[node][i].S = par[par[node][i - 1].S][i - 1].S;
        par[node][i].F = max(par[node][i].F, par[par[node][i - 1].S][i - 1].F);
        if (node == 2 && i <= 2) {
            // cout << par[node][i].F << " " << par[node][i].S << endl;
        }
    }

    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs_lca(child, node);
    }
}

ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_pre(1, 0);
    dfs_lca(1, 0);

    cin >> q;
    for (ll i = 1; i <= q; i++) {
        cin >> u >> k;
        k = min(k, dep[u]);
        ll ans = fur[u].F;
        ll diff = 0;
        for (ll i = lg; i >= 0; i--) {
            if ((1 << i) <= k) {
                diff += (1 << i);
                ans = max(ans, par[u][i].F + diff);
                // cout << ans << endl;
                // cout << par[u][i].F << endl;
                u = par[u][i].S;
                k -= (1 << i);
            }
        }

        cout << ans << ' ';
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}