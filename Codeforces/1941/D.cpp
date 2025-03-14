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
    cin >> n >> m >> x;

    set<ll> cur, tmp;
    cur.insert(x);
    for (int i = 0; i < m; i++) {
        char c; cin >> r >> c;
        for (auto it: cur) {
            if (c != '1') {
                tmp.insert((it + r) % n);
            }
            if (c != '0') {
                tmp.insert((it - r + n) % n);
            }
        }
        cur = tmp;
        tmp.clear();
        if (cur.count(0)) {
            cur.erase(0);
            cur.insert(n);
        }
    }

    cout << len(cur) << '\n';
    for (auto it: cur) {
        cout << it << ' ';
    }
    return cout << "" << '\n', 0;
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