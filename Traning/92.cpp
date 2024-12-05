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

const ll maxN = 1e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll p;
        cin >> p;

        l = -inf, r = inf;
        ll val, j;
        for (int i = 0; i < n; i++) {
            val = p - a[i];
            j = *lower_bound(a, a + n, val);
            if (j == val) {
                if (abs(l - r) > abs(a[i] - j)) {
                    l = a[i];
                    r = j;
                }
            }
        }

        cout << "Peter should buy books whose prices are ";
        cout << l << " and " << r << ".\n";
        cout << '\n';
    }

    return  0;
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