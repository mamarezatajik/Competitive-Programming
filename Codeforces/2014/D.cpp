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


ll ls[maxN], rs[maxN], n, d, k, dp[maxN], cnt[maxN];


ll _main() {
    cin >> n >> d >> k;

    for (ll i = 0; i < n + 10; i++) {
        dp[i] = cnt[i] = 0;
    }

    for (ll i = 0; i < k; i++) {
        cin >> ls[i] >> rs[i];
    }

    if (n < d) {
        return cout << "1 1\n", 0;
    }

    ll mx = n - d + 1;

    for (ll i = 0; i < k; i++) {
        ll u, v;
        u = max(1ll, ls[i] - d + 1);
        v = min(rs[i], mx);
        if (u <= v) {
            dp[u]++;
            dp[v + 1]--;
        }
    }

    ll ctr = 0; 
    for (ll i = 1; i <= mx; i++) {
        ctr += dp[i];
        cnt[i] = ctr;
    }

    ll mx_day = 1, mn_day = 1;

    for (ll i = 1; i <= mx; i++) {
        if (cnt[i] > cnt[mx_day]) {
            mx_day = i;
        }
        if (cnt[i] < cnt[mn_day]) {
            mn_day = i;
        }
    }

    cout << mx_day << ' ' << mn_day << '\n';
    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}