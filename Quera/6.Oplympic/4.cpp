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

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
// const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    cin >> n >> w;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> g (w);
    for (ll i = 0; i < w; i++) {
        cin >> g[i];
    }
    reverse(all(g));

    ll rem, val;
    vector<ll> ans(w, 0);
    for (ll i = 0; i < n; i++) {
        ll idx, cur = a[i];
        while (cur != 0) {
            idx = lower_bound(all(g), cur) - g.begin();
    
            if (idx == w) {
                idx--;
            }
            if (idx == 0 && cur < *g.begin()) {
                break;
            }

            if (g[idx] > cur) {
                idx--;
            }

            ll mod = g[idx];
            rem = cur % mod;
            val = cur - rem;
            ans[idx] += val;
            cur = rem;
        }
    }

    reverse(all(ans));
    for (ll i = 0; i < w; i++) {
        cout << ans[i] << " \n"[i == w - 1];
    }

    return 0;
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