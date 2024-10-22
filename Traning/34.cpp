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

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

ll n, m, k, q, u, v, x, y;
ll a[maxN], b[maxN], vis[maxN], turn[maxN];


ll _main() {
    cin >> n >> m >> q;

    ll cnt = 1, ans = true;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = false;
        turn[a[i]] = cnt++;
    }

    cnt = 1;
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
        if (!vis[b[i]]) {
            if (turn[b[i]] != cnt) {
                ans = false;
            }
            cnt++;
            vis[b[i]] = true;
        }
    }

    for (ll i = 0; i < q; i++) {
        ll s, t;
        cin >> s >> t;
    }

    return cout << (ans ? "YA" : "TIDAK") << '\n', 0;
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