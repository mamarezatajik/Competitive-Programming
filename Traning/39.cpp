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


ll n, m, k, p, q, u, v, w, x, y, z, l, r, h, timer = 1;
ll par[maxN][lg + 1], start[maxN], finish[maxN], dep[maxN], vis[maxN];
vector<ll> adj[maxN], cousin_st[maxN], cousin_fin[maxN];


void dfs_pre(ll node, ll parent) {
    vis[node] = true;
    start[node] = timer++;
    dep[node] = dep[parent] + 1;

    par[node][0] = parent;
    for (ll i = 1; i <= lg; i++) {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }

    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs_pre(child, node);
    }

    finish[node] = timer++;

    cousin_st[dep[node]].push_back(start[node]);
    cousin_fin[dep[node]].push_back(finish[node]);
}

pll go_up(ll node, ll h) {
    for (ll i = lg; i >= 0; i--) {
        if (h > (1 << i)) {
            h -= (1 << i);
            node = par[node][i];
        }
    }
    node = par[node][0];
    return {start[node], finish[node]};
}

ll _main() {
    cin >> n;
    for (u = 1; u <= n; u++) {
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_pre(i, 0);
        }
    }

    cin >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> v >> h;
        if (dep[v] <= h) {
            cout << 0;
        } 
        else {
            auto [st, fin] = go_up(v, h);
            l = upper_bound(all(cousin_st[dep[v]]), st) - cousin_st[dep[v]].begin();
            r = lower_bound(all(cousin_fin[dep[v]]), fin) - cousin_fin[dep[v]].begin();
            cout << (r - l - 1);
        }
        if (i != m) {
            cout << ' ';
        }
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