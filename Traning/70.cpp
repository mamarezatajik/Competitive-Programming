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

const ll maxN = 1e7 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
bool is_prime[maxN];


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        is_prime[i] = true;
    }

    ll ans = 0;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            ll j = 2 * i;
            while (j <= n) {
                is_prime[j] = false;
                j += i;
            }
            ans++;
        }
    }

    cout << ans << '\n';
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << ' ';
        }
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