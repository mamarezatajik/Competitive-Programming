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
    ll n, q; cin >> n >> q;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ls (q), rs (q);
    for (ll i = 0; i < q; i++) {
        cin >> ls[i] >> rs[i];
    }

    sort(all(ls));
    sort(all(rs));

    vector<ll> coeff;
    for (ll i = 1; i <= n; i++) {
        ll r = upper_bound(all(ls), i) - ls.begin();
        ll l = lower_bound(all(rs), i) - rs.begin();
        coeff.push_back(r - l);
    }

    sort(all(coeff));
    sort(a, a + n);

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += a[i] * coeff[i];
    }

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