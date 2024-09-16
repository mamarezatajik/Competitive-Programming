#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], special[maxN], Find[maxN], Size[maxN], done, n, m, k;
vector<pair<ll, pll>> edges;

void make_set(ll u) {
    Find[u] = u;
    Size[u] = special[u];
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

    if (u == v) {
        return;
    }

    if (Size[u] < Size[v]) {
        swap(u, v);
    }

    Size[u] += Size[v];
    Find[v] = u;
    if (Size[u] == k) {
        done = 1;
    }
}


ll _main() {
    cin >> n >> m >> k;

    for (ll i = 0; i < k; i++) {
        ll node;
        cin >> node;
        node--;
        special[node] = true;
    }

    for (ll i = 0; i < n; i++) {
        make_set(i);
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }

    sort(all(edges));

    done = 0;
    for (ll i = 0; i < m; i++) {
        auto [u, v] = edges[i].S;
        union_sets(u, v);

        if (done) {
            for (ll j = 0; j < k; j++) {
                cout << edges[i].F << ' ';
            }
            return 0;
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