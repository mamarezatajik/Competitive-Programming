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


ll _main() {
    ll A, B, C;
    cin >> A >> B >> C;
    for (ll x = -100; x <= 100; x++) {
        for (ll y = -100; y <= 100; y++) {
            for (ll z = -100; z <= 100; z++) {
                if (x == y || x == z || y == z) {
                    continue;
                }
                if (x + y + z == A &&
                    x * y * z == B &&
                    x * x + y * y + z * z == C) {
                        cout << x << " " << y << " " << z << '\n';
                        return 0;
                    }
            }
        }
    }

    return cout << "No solution.\n",0;
}


signed main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}