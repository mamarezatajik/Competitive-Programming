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


ll n, m, k, q, u, v, w, x, y, z, l, r;


ll _main() {
    cin >> n;
    vector<pll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S;
    }

    sort(all(a), [](const pll one, const pll two) {
        ll mn1, mn2, mx1, mx2;
        mn1 = min(one.F, one.S);
        mn2 = min(two.F, two.S);
        mx1 = max(one.F, one.S);
        mx2 = max(two.F, two.S);

        if (mn1 == mn2) {
            return mx1 < mx2;
        }
        return mn1 < mn2;
    });

    for (ll i = 0; i < n; i++) {
        cout << a[i].F << ' ' << a[i].S << ' ';
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