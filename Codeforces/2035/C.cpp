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


ll _main() {
    cin >> n;

    if (n % 2 == 1) {
        cout << n << '\n';
        for (ll i = 4; i < n - 1; i++) {
            cout << i << ' ';
        }
        cout << "2 3 1 " << (n - 1) << ' ' << n << '\n';
    }
    else {
        ll Lg = log2(n) + 1;
        ll ans = pow(2, Lg) - 1;
        cout << ans << '\n';

        ll m = pow(2, (Lg - 1)) - 1;
        if (m == 3) {
            m = 5;
        }
        for (ll i = 4; i < n; i++) {
            if (i != (m - 1) && i != m) {
                cout << i << ' ';
            }
        }
        cout << "2 3 1 " << (m - 1) << ' ' << m << ' ' << n << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}