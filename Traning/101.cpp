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
const ll inf  = 1e8 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, ctr = 1;
ll a[maxN];

bool check() {
    x = m;
    for (int i = 1; i <= n; i++) {
        if ((a[i] - a[i - 1]) > x) {
            return false;
        } else if (a[i] - a[i - 1] == x) {
            x--;
        }
    }
    return x >= 0;
}


ll _main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    l = 1, r = inf;
    while (l < r) {
        m = (l + r) / 2;
        // cout << l << ' ' << r << endl;
        if (check()) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << "Case " << ctr++ << ": ";
    return cout << r << '\n', 0;
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