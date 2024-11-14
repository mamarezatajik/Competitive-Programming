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
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<ll> idx;
        for (ll i = 0; i <= 32; i++) {
            if ((1ll << i) & n) {
                idx.push_back(i);
            }
        }

        ll a = 0, b = 0;
        for (ll i = 0; i < len(idx); i++) {
            if (i % 2 == 0) {
                a += (1ll << idx[i]);
            }
            else {
                b += (1ll << idx[i]);
            }
        }

        cout << a << ' ' << b << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}