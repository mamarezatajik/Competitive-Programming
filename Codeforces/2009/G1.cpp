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


ll a[maxN], dp[maxN];
pll seg[maxN * 4];

void build(ll node, ll l, ll r) {
    if (l == r) {
        seg[node] = {dp[l], l};
        return;
    }

    ll mid = (l + r) / 2;
    ll left = node << 1;
    ll right = node << 1 | 1;

    build(left, l, mid);
    build(right, mid + 1, r);

    seg[node] = max(seg[left], seg[right]);
}

pll query(ll node, ll l, ll r, ll L, ll R) {
    if (L <= l && r <= R) {
        return seg[node];
    }
    if (R < l || r < L) {
        return {-inf, 0};
    }

    ll mid = (l + r) / 2;
    ll left = node << 1;
    ll right = node << 1 | 1;

    return max(query(left, l, mid, L, R),
                query(right, mid + 1, r, L, R));
}


ll _main() {
    ll n, k, q;
    cin >> n >> k >> q;
    dp[0] = 0;
    a[0] = -inf;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        if (a[i - 1] + 1 == a[i]) {
            dp[i] += dp[i - 1];
        }
    }

    build(1, 1, n);

    while (q--) {
        ll l, r;
        cin >> l >> r;
        pll tmp = query(1, 1, n, l, r);
        ll mx = tmp.F,
            idx = tmp.S;
        ll minBound = idx - l + 1;

        mx = min(minBound, mx);
        if (minBound <= mx && idx < r) {
            mx = max(minBound, query(1, 1, n, idx + 1, r).F);
        }

        cout << max(0ll, k - mx) << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}