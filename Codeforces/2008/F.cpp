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

ll a[maxN], ps[maxN];

ll add(ll x, ll y) {
    return (((((x % mod) + (y % mod)) % mod) + mod) % mod);
}

ll neg(ll x, ll y) {
    return (((((x % mod) - (y % mod)) % mod) + mod) % mod);
}

ll mul (ll x, ll y) {
    return (((((x % mod) * (y % mod)) % mod) + mod) % mod);
}

ll pow(ll base, ll expo) {
    if (expo == 0) {
        return 1;
    }
    ll res = pow(mul(base, base), expo / 2);
    if (expo % 2 == 0) {
        return res;
    }
    return mul(base, res);
}

ll _main() {
    ll n; cin >> n;
    ps[0] = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = add(ps[i], a[i]);
    }

    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
        sum = add(sum, mul(a[i], neg(ps[n], ps[i + 1])));
    }

    ll q = n * (n - 1) / 2;
    ll ans = mul(sum, pow(q, mod - 2));

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