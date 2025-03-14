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

const ll maxN = 1e2 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, d;
ll morningRouts[maxN], eveningRouts[maxN];


ll _main() {
    while (cin >> n >> d >> r) {
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> morningRouts[i];
        }
        sort(morningRouts, morningRouts + n);
        for (int i = 0; i < n; i++) {
            cin >> eveningRouts[i];
        }
        sort(eveningRouts, eveningRouts + n);
        reverse(eveningRouts, eveningRouts + n);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += r * max(0ll, morningRouts[i] + eveningRouts[i] - d);
        }

        cout << ans << '\n';
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