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


ll n, m = 236, k, q, u, v, w, x, y, z, l, r;
ll _main();


ll naive() {
    ll ans = 0, val;
    // for (x = 3; x <= 10; x++) {
        ll mn = inf, mx = -inf;
        // _main();
        for (y = 1; y <= m; y++) {
            val = x ^ y;
            if (((val % x == 0) || (val % y == 0))) {
                // cout << "x = " << x << " y = " << y << " val = " << val << endl;
                // mn = min(mn, y);
                // mx = max(mx, val);
                ans++;
            }
        }
        // cout << "x = " << x;
        // cout << " mx = " << mx << endl;
        // cout << x << endl;
        // cout << "real ans = " << ans << endl;
        return ans;
    // }
    return 0;
}

ll _main() {
    cin >> x >> m;
    // for (m = 1; m <= 10000; m++) 
    // for (x = 2; x <= 10000; x++) {
    // x = 9;44244
    // naive();

        if (x == 1) {
            return cout << m << '\n', 0;
        }

        ll ans = 0, val;
        for (y = 1; y <= min(x, m); y++) {
            val = x ^ y;
            if (((val % x == 0) || (val % y == 0))) {
                ans++;
            }
        }

        // cout << ans << endl;

        ll last = ((m + x) / x) * x - 3 * x;
        ll first = 2 * x;
        // cout << first << ' ' << last << endl;
        if (last > 0 && last >= first + x) {
            ans += (last - first + x) / x;
        } else {
            last = 0;
        }

        // cout << ans << endl;



        ll start = x;
        if (last > 0) {
            start += (last / x) * x;
        }
        start = max(start, 2 * x);
        ll end = start + 10 * x;

        // cout << start << ' ' << end << endl;
        // cout << ans << endl;


        for (val = end; val >= start; val -= x) {
            y = x ^ val;
            // cout << val << ' ' << y << endl;
            if (y <= m) {
                ans++;
            }
        }

        // cout << "my ans = ";
        // cout << ans << endl;
        // if (naive() != ans) {
        //     cout << x;
        //     return 0;
        // }
    // }
    // return 0;
    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // naive();
    // exit(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}