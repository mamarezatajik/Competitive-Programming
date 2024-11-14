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

const ll maxN = 1e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
vector<int> adj[maxN];

ll _main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (len(adj[x]) == 0) {
                adj[x].push_back(0);
            }
            adj[x].push_back(i);
        }
        for (ll i = 1; i <= m; i++) {
            cin >> k >> v;
            if (k >= len(adj[v])) {
                cout << 0 << '\n'; 
            } else {
                cout << adj[v][k] << '\n';
            }
        }
    }

    return 0;
}


signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}