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
    ll n, m, k, w;
    cin >> n >> m;
    cin >> k >> w;

    for (ll i = 0; i < w; i++) 
        cin >> a[i];

    sort(a, a + w); reverse(a, a + w);
    vector<ll> coeff;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll i1 = max(0ll, i - k + 1);
            ll i2 = min(n - 1, i + k - 1);
            ll j1 = max(0ll, j - k + 1);
            ll j2 = min(m - 1, j + k - 1);
            coeff.push_back((i2 - i1 + 2 - k) * (j2 - j1 + 2 - k));
        }
    }

    sort(rbegin(coeff), rend(coeff));

    ll ans = 0;
    for (ll i = 0; i < w; i++) 
        ans += a[i] * coeff[i];

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