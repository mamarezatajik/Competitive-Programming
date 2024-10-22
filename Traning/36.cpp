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
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN], dp[maxN][2];


ll _main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = dp[0][1] = 1;
    // 0 --> up
    // 1 --> down

    ll ans = 1;
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            if (a[i] < a[j]) {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
    }

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}