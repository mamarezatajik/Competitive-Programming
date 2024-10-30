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

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll cnt[maxN], dp[maxN];


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> u;
        cnt[u]++;
    }

    dp[1] = cnt[1];
    for (ll i = 1; i <= maxN - 2; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }

    return cout << dp[maxN - 2], 0;
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