#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<int, int>        pii;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e4 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;



ll _main() {
    ll n, m, r;
    while (cin >> n >> m) {
        vector<vector<pii>> adj(m + 1, vector<pii>());

        for (ll i = 1; i <= n; i++) {
            cin >> r;
            if (r == 0) {
                continue;
            }
            vector<int> indices (r);
            for (int &index: indices) {
                cin >> index;
            }
            vector<int> values (r);
            for (int &value: values) {
                cin >> value;
            }

            for (ll j = 0; j < r; j++) {
                adj[indices[j]].push_back({i, values[j]});
            }
        }

        cout << m << ' ' << n << '\n';
        for (ll j = 1; j <= m; j++) {
            r = len(adj[j]);
            cout << r;
            for (ll i = 0; i < r; i++) {
                cout << ' ' << adj[j][i].F;
            } cout << '\n';
            for (ll i = 0; i < r; i++) {
                cout << adj[j][i].S;
                if (i != r - 1) {
                    cout << ' ';
                }
            } cout << '\n';
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