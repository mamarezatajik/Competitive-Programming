#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN];


ll _main() {
    ll n; cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n, 0);
    ll cur, pre = a[0], cnt = 0, mx = a[0];
    for (ll i = 1; i < n; i++) {
        cur = a[i];
        cnt = 0;
        if (cur < pre) {
            if (cur == 1) {
                return cout << "-1\n", 0;
            }
            while (cur < pre) {
                cur *= cur;
                cnt++;
            }
            dp[i] = dp[i - 1] + cnt;
        }
        else {
            while (cur < mx) {
                cur *= cur;
                cnt++;
            }
            dp[i] = cnt;
        }

        mx = max(mx, cur);

        while (cnt--) {
            cur = sqrt(cur);
        }

        pre = cur;
    }

    ll ans = accumulate(all(dp), 0ll);

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}