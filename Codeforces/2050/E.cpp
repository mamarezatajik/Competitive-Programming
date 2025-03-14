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

ll _main() {
    string a, b, c;
    cin >> a >> b >> c;

    ll n = len(a), m = len(b);
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, inf));
    dp[0][0] = 0;

    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            if (i > 0 && i + j - 1 < len(c)) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (c[i + j - 1] != a[i - 1]));
            }
            if (j > 0 && i + j - 1 < len(c)) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
            }
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
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