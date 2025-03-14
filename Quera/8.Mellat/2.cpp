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

const ll maxN = 1000 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll add[maxN];


ll _main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        add[u] -= w;
        add[v] += w;
    }

    vector<pair<pll, ll>> ans;
    for (int i = 1; i <= n; i++) {
        if (add[i] > 0) {
            for (int j = 1; j <= n; j++) {
                if (add[i] == 0) {
                    break;
                }
                if (add[j] < 0) {
                    ll tmp = min(add[i], -add[j]);
                    add[i] -= tmp;
                    add[j] += tmp;
                    ans.push_back({{j, i}, tmp});
                }
            }
        }
    }

    cout << len(ans) << '\n';
    for (auto [uv, ww]: ans) {
        auto [l, r] = uv;
        cout << l << ' ' << r << ' ' << ww << '\n';
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