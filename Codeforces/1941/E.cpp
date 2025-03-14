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


ll n, m, k, q, u, v, w, x, y, z, l, r, d;
ll a[maxN];


ll _main() {
    cin >> n >> m >> k >> d;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        vector<long long> dp(m, 1e9);
        vector<int> v(m);
        multiset<long long> mst = {1};
        dp[0] = 1;
        cin >> v[0];
        for (int j = 1; j < m - 1; j++) {
            cin >> v[j];
            dp[j] = *mst.begin() + v[j] + 1;
            if (j - d - 1 >= 0)
                mst.erase(mst.find((dp[j - d - 1])));
            mst.insert(dp[j]);
        }
        cin >> v.back();
        dp.back() = 1 + *mst.begin();
        a[i] = dp.back();
    }

    ll cur = 0;
    for (int i = 0; i < k; i++) {
        cur += a[i];
    }

    ll mn = cur;
    for (int i = k; i < n; i++) {
        cur += a[i] - a[i - k];
        mn = min(cur, mn);
    }

    return cout << mn << '\n', 0;
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