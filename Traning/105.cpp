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

const ll maxN = 1e3 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;


ll _main() {
    cin >> n;
    vector<ll> coins (n + 1);
    coins[n] = inf;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    ll curCoin, nxtCoin;
    ll sum = 0, ans = 0;
    ll i = 0;
    for (int j = 1; j <= n; j++) {
        curCoin = coins[i];
        nxtCoin = coins[j];
        if (sum + curCoin < nxtCoin) {
            sum += curCoin;
            ans++;
        }
        i++;
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