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

ll ctr = 1;

ll _main() {
    ll b, s;
    cin >> b >> s;
    if (b == 0) {
        exit(0);
    }
    vector<ll> bach(b), spin(s);
    for (int i = 0; i < b; i++) {
        cin >> bach[i];
    }
    for (int i = 0; i < s; i++) {
        cin >> spin[i];
    }

    cout << "Case " << ctr++ << ": ";
    if (b > s) {
        cout << b - s << ' ' << *min_element(all(bach));
    } else {
        cout << 0;
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc) {
        _main();
    }
    return 0;
}