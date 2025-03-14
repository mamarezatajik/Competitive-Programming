#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    cin >> n;
    ll sum = 0, sumOdd = 0, sumEvn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) {
            sumEvn += a[i];
        } else {
            sumOdd += a[i];
        }
        sum += a[i];
    }

    if (sum % n != 0) {
        return cout << "NO\n", 0;
    }

    ll div = sum / n;
    if (sumEvn % div == 0 && sumEvn / div == (n + 1) / 2 &&
        sumOdd % div == 0 && sumOdd / div == n / 2) {
            return cout << "YES\n", 0;
        }

    return cout << "NO" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}