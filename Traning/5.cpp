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

const ll maxN = 3e4 + 10;
const ll inf = 8e18;
const ll mod = 1e9 + 7; //998244353; //1e9 + 9;

ll t;
vector<ll> adj[maxN];


bool dfs(ll node, ll parent) {
    if (node == t)
        return true;
    for (ll child : adj[node])
        return dfs(child, node);
    return false;
}


ll _main() {
    ll n; cin >> n >> t;
    for (ll i = 0; i < maxN; i++) 
        adj[i] = vector<ll>();

    for (ll dst, src = 1; src < n; src++) {
        cin >> dst; 
        adj[src].push_back(src + dst);
    }

    return print(dfs(1, t) ? "YES" : "NO"), 0;
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}