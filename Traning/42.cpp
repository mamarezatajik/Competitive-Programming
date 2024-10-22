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


ll n, m, k, q, u, v, w, x, y, z, l, r,
    a, b, h, p;


ll _main() {
    while (scanf("%d %d %d %d\n", &n, &b, &h, &w) != EOF) {
        ll ans = inf;
        for (ll i = 1; i <= h; i++) {
            cin >> p;
            for (ll i = 1; i <= w; i++) {
                cin >> a;
                if (((p * n) <= b)
                    && (a >= n)) {
                        ans = min(ans, p * n);
                        string s;
                        getline(cin, s);
                        break;
                }
            }
        }
        if (ans == inf) {
            cout << "stay home";
        }
        else {
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}


signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}