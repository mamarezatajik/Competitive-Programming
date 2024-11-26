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

const ll maxN = 5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    bool first = true;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        if (!first) {
            cout << '\n';
        }

        if (first) {
            first = false;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int u = k + 1; u < n; u++) {
                        for (int v = u + 1; v < n; v++) {
                            for (int w = v + 1; w < n; w++) {
                                cout << a[i] << ' ';
                                cout << a[j] << ' ';
                                cout << a[k] << ' ';
                                cout << a[u] << ' ';
                                cout << a[v] << ' ';
                                cout << a[w] << '\n';
                            }
                        }
                    }
                }
            }
        }
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