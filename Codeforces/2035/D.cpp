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

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, dp[maxN], a[maxN];

ll mul(ll a, ll b) {
    ll res = a * b;
    if (res > mod) {
        return res % mod;
    }
    return res;
}

ll add(ll a, ll b) {
    ll res = a + b;
    if (res > mod) {
        return res % mod;
    }
    return res;
}

ll power(ll base, ll expo) {
    if (expo == 0) {
        return 1;
    }
    ll res = power(mul(base, base), expo / 2);
    if (expo % 2 == 0) {
        return res;
    }
    return mul(res, base);
}


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll sum = 0, cnt = 0;
    dp[1] = a[1];
    for (ll i = 1; i <= n; i++) {
        if (i != 1) {
            dp[i] = max(dp[i - 1] + a[i], 
                sum + power(2, cnt) * a[i]);
            dp[i - 1] %= mod;
        }

        while (a[i] % 2 == 0) {
            cnt++;
            a[i] /= 2;
        }
        sum = add(sum, a[i]);
    } dp[n] %= mod;

    for (ll i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }

    return cout << "" << '\n', 0;
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