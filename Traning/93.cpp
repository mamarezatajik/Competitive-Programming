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

const ll maxN = 5e2 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;


ll _main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<ll>> a (n + m - 1, vector<ll>());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                a[(n > m ? n - i + j : m + i - j) - 1].push_back(x);
            }
        }

        cin >> q;
        while (q--) {
            cin >> l >> r;
            ll left, right;

            ll ans = 0;
            for (int i = 0; i < n + m - 1; i++) {
                left = lower_bound(all(a[i]), l) - a[i].begin();
                right = upper_bound(all(a[i]), r) - a[i].begin() - 1;
                ans = max(ans, right - left + 1);
            }

            cout << ans << '\n';
        }
        cout << "-\n";
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}