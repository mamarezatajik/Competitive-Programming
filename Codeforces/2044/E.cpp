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



ll _main() {
    ll K, l1, r1, l2, r2;
    cin >> K >> l1 >> r1 >> l2 >> r2;

    ll count = 0;
    ll power = 1;

    while (true) {
        if (power > r2 / l1) {
            break;
        }

        ll x_min = max(l1, (l2 + power - 1) / power);
        ll x_max = min(r1, r2 / power);

        if (x_min <= x_max) count += (x_max - x_min + 1);

        if (power > r2 / K) {
            break;
        }
        power *= K;
    }

    return cout << count << '\n', 0;
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