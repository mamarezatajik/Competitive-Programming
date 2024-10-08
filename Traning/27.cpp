#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], n, m, Find[maxN], Size[maxN], done, ans;
vector<pair<ll, pll>> edges;

void make_set(ll u) {
    Find[u] = u;
    Size[u] = 1;
}

ll find_set(ll u) {
    if (Find[u] != u) {
        Find[u] = find_set(Find[u]);
    }
    return Find[u];
}

bool union_sets(ll u, ll v) {
    u = find_set(u);
    v = find_set(v);

    if (u == v) {
        return false;
    }

    if (Size[u] < Size[v]) {
        swap(u, v);
    }

    Size[u] += Size[v];
    Find[v] = u;
    if (Size[u] == n) {
        done = true;
    }
    return true;
}


ll _main() {
    cin >> n >> m;

    ll mn = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[mn] > a[i]) {
            mn = i;
        }
    }

    for (ll i = 0; i < n; i++) {
        edges.push_back({a[mn] + a[i], {mn, i}});
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }

    sort(all(edges));
    m += n;

    for (ll i = 0; i < n; i++) {
        make_set(i);
    }

    done = false;
    ans = 0;
    for (ll i = 0; i < m; i++) {
        auto [u, v] = edges[i].S;
        ll w = edges[i].F;
        if (union_sets(u, v)) {
            ans += w;
        }
        if (done) {
            break;
        }
    }

    return cout << ans, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}