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


ll _main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, pll>> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].S.F >> a[i].S.S;
        a[i].F = a[i].S.F - a[i].S.S;
    }

    sort(all(a));
    reverse(all(a));

    ll ans = 0;
    for (ll i = 0; i < min(n, m); i++) {
        ans += a[i].S.F;
    }
    for (ll i = m; i < n; i++) {
        ans += a[i].S.S;
    }

    cout << ans;
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