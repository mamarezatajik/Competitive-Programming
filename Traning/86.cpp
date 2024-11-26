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

const ll maxN = 5 + 5;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN][maxN];
map<ll, pll> mapping;

void pre() {
    ll cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mapping[cnt++] = {i, j};
        }
    }
}

ll dist(pll f, pll s) {
    return abs(f.F - s.F) + abs(f.S - s.S);
}


ll calcCost() {
    ll cost = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            pll s = {i, j};
            ll minCost = min({
                dist(mapping[u], s),
                dist(mapping[v], s),
                dist(mapping[w], s),
                dist(mapping[x], s),
                dist(mapping[y], s)
            });
            cost += minCost * a[i][j];
        }
    }
    return cost;
}

ll _main() {
    cin >> n;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> v;
        a[l][r] = v;
    }

    m = 25;
    ll bestCost = inf;
    vector<ll> ans (5);
    for (u = 0; u < m; u++) {
        for (v = u + 1; v < m; v++) {
            for (w = v + 1; w < m; w++) {
                for (x = w + 1; x < m; x++) {
                    for (y = x + 1; y < m; y++) {

                        ll cost = calcCost();
                        if (bestCost > cost) {
                            bestCost = cost;
                            ans[0] = u;
                            ans[1] = v;
                            ans[2] = w;
                            ans[3] = x;
                            ans[4] = y;
                        }
                    }
                }
            }
        }
    }

    cout << ans[0];
    for (int i = 1; i < 5; i++) {
        cout << ' ' << ans[i];
    } cout << '\n';


    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pre();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}