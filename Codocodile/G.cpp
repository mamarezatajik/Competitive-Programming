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

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[8][1024];


ll _main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> u >> v >> w;
        for (int m = 0; m < 8; m++) {
            ll sum = 0;
            if (m & 1) sum += u; else sum -= u;
            if (m & 2) sum += v; else sum -= v;
            if (m & 4) sum += w; else sum -= w;
            a[m][i] = sum;
        }
    }

    ll res = 0;
    for (int i = 0; i < 8; i++) {
        ll *b = a[i];
        sort(b + 1, b + 1 + n);
        reverse(b + 1, b + 1 + n);
        ll ans = 0;
        for (ll j = 1; j <= k; j++) {
            ans += b[j];
        }
        res = max(res, ans);
    }

    return cout << res << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}