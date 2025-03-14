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

ll a[maxN];

struct SegmentTree {
    vector<ll> tree;
    ll n;

    void build(const vector<ll>& a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) {
            return 0;
        } 
        if (tl == l && tr == r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return gcd(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    SegmentTree(const vector<ll>& a) {
        n = len(a);
        tree.resize(4 * max(1LL, n));
        if (n > 0) build(a, 1, 0, n - 1);
    }

    ll query(ll l, ll r) {
        if (n == 0 || l == r + 1) {
            return 0;
        }
        return query(1, 0, n - 1, l, r);
    }
};

ll _main() {
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        while (q--) {
            ll l, r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        return cout << '\n', 0;
    }

    vector<ll> diff(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i + 1] - a[i]);
    }

    SegmentTree st(diff);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(l, r - 1) << " ";
    }

    cout << '\n';
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        _main();
    }

    return 0;
}