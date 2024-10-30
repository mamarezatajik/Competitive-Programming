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

const ll maxN = (1 << 15) + 100;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n;
ll weights[maxN], potency[maxN];


ll _main() {
    while (cin >> n) {
        ll total = (1 << n);  
        for (ll msk = 0; msk < total; msk++) {
            cin >> weights[msk];
            potency[msk] = 0;
        }

        for (ll msk = 0; msk < total; msk++) {
            for (ll j = 0; j < n; j++) {
                potency[msk] += weights[msk ^ (1 << j)];
            }
        }

        ll ans = 0;
        for (ll msk = 0; msk < total; msk++) {
            for (ll j = 0; j < n; j++) {
                ans = max(ans, potency[msk] + potency[msk ^ (1 << j)]);
            }
        }

        cout << ans << '\n';
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