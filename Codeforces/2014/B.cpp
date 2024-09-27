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
    ll n, k;
    cin >> n >> k;

    ll l = n - k + 1;
    ll r = n;

    ll cnt = (r - l + 1) / 2;
    if (l % 2 == 1 && r % 2 == 1) {
        cnt++;
    }

    bool ok = cnt % 2 == 0;


    return cout << (ok ? "YES": "NO") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}