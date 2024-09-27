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
    double n; cin >> n;

    double sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1 || n == 2) {
        return cout << "-1\n", 0;
    }

    sort(a, a + (ll) n);
    double mn = a[((ll) n / 2)];

    ll l = 0, r = inf;
    double m;
    while (l < r) {
        m = (l + r) / 2;
        if (mn < ((sum + m) / (2.0 * n))) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    return cout << r << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}