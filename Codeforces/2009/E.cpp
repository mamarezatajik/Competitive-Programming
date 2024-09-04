#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN];


ll _main() {
    ll n, k;
    cin >> n >> k;

    ll l = k, r = n + k - 1;
    ll ans = inf, m, val;
    ll a, b;

    while (l < r) {
        m = (l + r) / 2;
        a = (k + m) * (m - k + 1) / 2;
        b = (m + 1 + n + k - 1) * (n + k - 1 - (m + 1) + 1) / 2;
        val = abs(a - b);
        ans = min(ans, val);
        if (a < b) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }

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