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
ll fib[maxN];


ll _main() {
    cin >> n >> k;

    fib[1] = fib[2] = 1;
    for (ll i = 1; i <= 2e6; i++) {
        if (i > 2) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        fib[i] %= k;
        if (fib[i] == 0) {
            return cout << (((n % mod) * i) % mod) << '\n', 0;
        }
    }

    return cout << "" << '\n', 0;
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