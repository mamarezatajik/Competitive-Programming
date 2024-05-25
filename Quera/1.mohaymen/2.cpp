#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io             ios_base::sync_with_stdio(false);\
                                cin.tie(0); cout.tie(0)
#define print(n)            cout << (n) << '\n'
#define print_vec(arr)      for (auto __ : arr)\
                                cout << __ << ' '; cout << '\n'
#define print_vec_vec(arr)  for (auto _ : arr)\
                                {print_vec(_);}; cout << '\n'
#define all(arr)            arr.begin(), arr.end()
#define rall(arr)           arr.rbegin(), arr.rend()
#define len(arr)            (ll) (arr.size())
#define Max(arr)            *max_element(all(arr))
#define Min(arr)            *min_element(all(arr))
#define Sum(arr)            accumulate(all(arr), 0ll)
#define ordered_set         tree<ll, null_type,less<ll>,\
                                rb_tree_tag,\
                                tree_order_statistics_node_update>
#define ll_max              LONG_LONG_MAX
#define ll_min              LONG_LONG_MIN
#define vec                 vector
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


ll mod = 1e9 + 7;

vec<vec<ll>> adj;
vec<ll> color, par, vis;
set<ll> in_cycle;
ll k, ans = ll_max, last = -1;

void dfs1(ll u, ll v) {
    if (color[u] == 2)
        return;

    if (color[u] == 1) {
        ll cur = v;
        in_cycle.insert(cur);

        while (cur != u) {
            cur = par[cur];
            in_cycle.insert(cur);
        }
        return;
    }

    par[u] = v;
    color[u] = 1;

    for (ll v : adj[u]) {
        if (v == par[u])
            continue;
        dfs1(v, u);
    }

    color[u] = 2;
}


void dfs2(ll u, ll p, ll dep) {
    if (in_cycle.count(u) && dep < ans) {
        ans = dep;
        last = u;
    }
    vis[u] = true;
    par[u] = p;
    for (ll v : adj[u])
        if (!vis[v])
            dfs2(v, u, dep + 1);
}

ll _main() {
    ll n, m; cin >> k >> n >> m;
    k--;
    adj.resize(n, vec<ll>());
    par.resize(n);
    vis.resize(n, false);
    color.resize(n);
    in_cycle.clear();
    ll u, v;


    for (ll i = 0; i < m; i++) {
        cin >> u >> v; 
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(0, 0);
    fill(all(par), -1);

    dfs2(k, k, 0);

    vec<ll> path = {};
    while (par[last] != last) {
        path.pb(last + 1);
        last = par[last];
    } path.pb(k + 1);
    reverse(all(path));

    print_vec(path);

    return 0;
}


signed main() {
    fast_io;

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}