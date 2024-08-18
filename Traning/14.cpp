#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e3 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, k, d, ans, dp[maxN][2];

ll dfs(ll sum, bool haveD) {
    if (dp[sum][haveD] != -1) {
        return dp[sum][haveD];
    }

    dp[sum][haveD] = 0;
    for (ll i = 1; i <= k; i++) {
        if (sum >= i) {
            dp[sum][haveD] += dfs(sum - i, haveD | (i >= d));
            dp[sum][haveD] %= mod;
        }
    }
    return dp[sum][haveD];
}


ll _main() {
    cin >> n >> k >> d;
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[0][0] = 0; 
    dp[0][1] = 1;

    ans = dfs(n, false);

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}