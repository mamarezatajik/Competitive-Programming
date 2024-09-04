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
    ll n;
    cin >> n;

    vector<vector<bool>> a (n + 1, vector<bool>(2, false));
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[x][y] = true;
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (a[i][0] && a[i][0] == a[i][1]) {
            ans += (n - 2);
        }
        if (i == 0 || i == n - 1) {
            continue;
        }
        for (ll j = 0; j < 2; j++) {
            if (a[i][j] && a[i - 1][j ^ 1] && a[i + 1][j ^ 1]) {
                ans++;
            }
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