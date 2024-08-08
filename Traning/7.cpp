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

const ll maxN = 2e6 + 10;
const ll inf = 8e18;
const ll mod = 1e9 + 7; //998244353; //1e9 + 9;


ll Find[maxN], Size[maxN];

void make_set(ll u) {
    Find[u] = u;
    Size[u] = 1;
}

ll find_set(ll u) {
    return u == Find[u] ? u : find_set(Find[u]);
}

void union_sets(ll u, ll v) {
    u = find_set(u);
    v = find_set(v);

    if (u != v) {
        if (Size[u] < Size[v]) // Size of u must be greater than v
            swap(u, v);
        Find[v] = u;
        Size[u] += Size[v];
    }
}


ll _main() {
    ll n, m , k;
    cin >> n >> m;

    for (ll i = 0; i < n; i++) 
        make_set(i);

    for (ll u, i = 0; i < m; i++) {
        cin >> k;
        if (k != 0) {
            cin >> u; u--;
        }
        for (ll v, j = 1; j < k; j++) {
            cin >> v; v--;
            union_sets(u, v);
        }
    }

    for (ll i = 0; i < n; i++)
        cout << Size[find_set(i)] << ' ';

    return 0;
}


signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}