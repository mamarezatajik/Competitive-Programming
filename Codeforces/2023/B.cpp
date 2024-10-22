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

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll sum = 0, less = 0, diff = 0;
    a[0] = -inf;
    for (ll i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            diff++;
            continue;
        }
        sum += ((n - i + 1) * (a[i] - less));
        if (sum >= k) {
            return cout << (k + diff) << '\n', 0;
        }
        diff++;
        less = a[i];
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}