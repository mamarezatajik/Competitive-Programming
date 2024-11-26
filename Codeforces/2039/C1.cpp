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


ll naive() {
    ll ans = 0, val;
    for (ll x = 1e7; x <= 1e7; x++) {
        ll mn = inf, mx = -inf;
        for (y = 1; y <= 1e8; y++) {
            val = x ^ y;
            if ((val != 0) && ((x % val == 0) || (y % val == 0))) {
                mn = min(mn, y);
                mx = max(mx, y);
                ans++;
            }
        }
        cout << "x = " << x;
        cout << " mn = " << mn << " mx = " << mx << endl;
        cout << "ans = " << ans << endl;
    }
    return 0;
}

ll _main() {
    cin >> x >> m;

    ll ans = 0, val;
    for (y = max(1ll, x / 2); y <= min(2 * x, m); y++) {
        val = x ^ y;
        if ((val != 0) && ((x % val == 0) || (y % val == 0))) {
            ans++;
        }
    }

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}