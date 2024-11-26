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


ll _main() {
    while (cin >> n) {
        vector<string> s (n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        ll maxDist = -inf;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (s[i][j] != '1') {
                    continue;
                }
                // find 1's:

                ll minDist = inf;
                for (ll u = 0; u < n; u++) {
                    for (ll v = 0; v < n; v++) {
                        if (s[u][v] != '3') {
                            continue;
                        }
                        // find 3's:
                        minDist = min(minDist, abs(i - u) + abs(j - v));
                    }
                }
                maxDist = max(maxDist, minDist);
            }
        }

        cout << maxDist << '\n';
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