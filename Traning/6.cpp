#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

template <class T> using ordered_set = tree<T, null_type,
less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()
#define print(a)            cout << (a) << '\n'
#define print_vec(a)        for (auto __ : a) cout << __ << ' '; cout << '\n'
#define print_vec_vec(a)    for (auto _ : a) { print_vec(_); } ; cout << '\n'

const ll maxN = 2e5 + 10;
const ll inf = 8e18;
const ll mod = 1e9 + 7; //998244353; //1e9 + 9;


ll a[maxN], mn;
vector<ll> adj[maxN];
bool vis[maxN];


void dfs(ll node) {
    vis[node] = true;
    mn = min(mn, a[node]);

    for (ll child : adj[node])
        if (!vis[child])
            dfs(child);
}

ll _main() {
    ll n, m; cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        adj[i] = vector<ll>();
    }

    for (ll u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--   ,   v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            mn = inf;
            dfs(i);
            ans += mn;
        }
    }

    return print(ans), 0;
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}