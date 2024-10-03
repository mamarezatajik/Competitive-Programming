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
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN];


ll _main() {
    ll n; cin >> n;

    ll mx1 = 0, mx2 = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) {
            mx1 = max(mx1, a[i]);
        }
        else {
            mx2 = max(mx2, a[i]);
        }
    }

    ll ans = max(mx1 + (n + 1) / 2, mx2 + n / 2);

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