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
const ld eps  = 1e-7;


ld p, q, r, s, t, u;

ld check(ld x) {
    return  p * exp(-x)+
            q * sin(x) +
            r * cos(x) +
            s * tan(x) +
            t * x * x  +
            u;
}



ll _main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        ld l = 0.0, r = 1.0, m, x = l, val;
        if (check(l) * check(r) > 0) {
            cout << "No solution\n";
            continue;
        }


        while (l + eps < r) {
            m = (l + r) / 2.0;
            if (check(l) * check(m) <= 0.0) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << fixed << setprecision(4) << (l + r) / 2.0 << '\n';
    }

    return 0;
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