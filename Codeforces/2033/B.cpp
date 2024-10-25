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

const ll maxN = 500 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN][maxN];


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ll m = n, ans = 0;
    for (ll d = 1 - n; d <= 0; d++) {
        ll mn1 = 0, mn2 = 0;
        for (ll i = 1; i <= n; i++) {
            if (1 <= i - d && i - d <= n) {
                mn1 = min(mn1, a[i - d][i]);
            }
            if (d != 0 && 1 <= i + d && i + d <= n) {
                mn2 = min(mn2, a[i + d][i]);
            }
        }
        ans += abs(mn1);
        ans += abs(mn2);
    }

    return cout << ans << '\n', 0;
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