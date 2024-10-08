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


ll a[maxN], ps[maxN], sum, n, q;

ll query(ll idx) {
    ll cnt = idx / n;
    ll rem = idx % n;

    ll ans = cnt * sum;
    ll diff = 0;

    if (rem != 0) {
        if (rem + cnt <= n) {
            diff = ps[rem + cnt] - ps[cnt];
        }
        else {
            diff = sum - ps[cnt] + ps[rem + cnt - n];
        }
    }

    return ans + diff;
}


ll _main() {
    cin >> n >> q;

    ps[0] = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    sum = ps[n];

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << query(r) - query(l - 1) << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}