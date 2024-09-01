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
    ll n, m; 
    cin >> n >> m;

    ll ans = -1;
    for (ll x, i = 0; i < n; i++) {
        cin >> x;
        ans = max(ans, x);
    }

    for (ll i = 0; i < m; i++) {
        char c;
        ll l, r;
        cin >> c >> l >> r;
        if (l <= ans && ans <= r) {
            if (c == '+')
                ans++;
            else
                ans--;
        }
        cout << ans << ' ';
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}