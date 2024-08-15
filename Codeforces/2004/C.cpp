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
    ll n, k; cin >> n >> k;

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ll ans = 0;

    for (ll i = n - 2; i >= 0; i -= 2) {
        if (a[i] < a[i + 1]) {
            ll diff = a[i + 1] - a[i];
            a[i] = a[i] + min(diff, k);
            k -= min(diff, k);
        }
        ans += a[i + 1] - a[i];
    }

    if (n % 2 == 1)
        ans += a[0];

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