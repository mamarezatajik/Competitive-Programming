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

ll lcm(ll a, ll b) {
    return (a * b / __gcd(a, b));
}

ll _main() {
    ll n; cin >> n;

    ll ans = 0, l = 1;
    for (ll i = 1; l <= n; i++) {
        l = lcm(l, i);
        if (l > n) {
            break;
        }
        ans += (n / l) % mod;
    }

    return cout << (ans + n) % mod << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}