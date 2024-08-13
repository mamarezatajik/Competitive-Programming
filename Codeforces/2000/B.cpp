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


ll _main() {
    ll n; cin >> n;

    ll cur;
    cin >> cur; cur--;

    vector<bool> dp (n, false);
    dp[cur] = true;

    bool ok = true;
    for (ll i = 1; i < n; i++) {
        cin >> cur; cur--;
        if ((cur > 0 && dp[cur - 1]) ||
            (cur + 1 < n && dp[cur + 1]))
                dp[cur] = true;
        else
            ok = false;
    }

    return cout << (ok ? "YES" : "NO") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}