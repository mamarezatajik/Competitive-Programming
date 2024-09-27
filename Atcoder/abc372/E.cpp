#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type,
less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll Size[maxN], Find[maxN];
ordered_set<ll> st[maxN];

void make_set(ll u) {
    st[u].insert(u);
    Size[u] = 1;
    Find[u] = u;
}

ll find_set(ll u) {
    if (Find[u] != u) {
        Find[u] = find_set(Find[u]);
    }
    return Find[u];
}

void union_sets(ll u, ll v) {
    u = find_set(u);
    v = find_set(v);

    if (u != v) {
        if (Size[u] < Size[v]) {
            swap(u, v);
        }
        Size[u] += Size[v];
        Find[v] = u;
        for (ll x: st[v]) {
            st[u].insert(x);
        }
    }
}

ll _main() {
    ll n, q;
    cin >> n >> q;

    for (ll i = 1; i <= n; i++) {
        make_set(i);
    }

    for (ll i = 0; i < q; i++) {
        ll m, u, v, k;
        cin >> m;
        if (m == 1) {
            cin >> u >> v;
        }
        else {
            cin >> v >> k;
        }

        if (m == 1) {
            union_sets(u, v);
        }
        else {
            v = find_set(v);
            if (k > len(st[v])) {
                cout << -1;
            }
            else {
                cout << (*st[v].find_by_order(len(st[v]) - k));
            }
            cout << '\n';
        }
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}