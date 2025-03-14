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
ll a[maxN], b[maxN];


ll _main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pll> firstMAx, secondMax;
    ll mxm = -inf;
    for (int i = 0; i < n; i++) {
        u = a[i], v = b[i];
        (u >= v ? firstMAx : secondMax).push_back({u, v});
        mxm = max(mxm, min(u, v));
    }

    ll ans = mxm;
    for (int i = 0; i < len(firstMAx); i++) {
        ans += firstMAx[i].F;
    } 
    for (int i = 0; i < len(secondMax); i++) {
        ans += secondMax[i].S;
    }

    return cout << ans << '\n', 0;
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