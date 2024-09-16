#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;



ll _main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> a (m);

    for (ll i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(all(a));

    for (ll i = 0; i < q; i++) {
        ll x, l = -1, r = -1;
        cin >> x;

        if (x < a[0]) {
            l = a[0];
        }
        else {
            l = a[lower_bound(all(a), x) - a.begin() - 1];
        }

        if (a[m - 1] < x) {
            r = a[m - 1];
        }
        else {
            r = a[lower_bound(all(a), x) - a.begin()];
        }

        if (l <= x && x <= r) {
            cout << (r - x + x - l) / 2;
        }
        else if (l > x) {
            cout << l - 1;
        }
        else {
            cout << n - r;
        }

        cout << '\n';
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