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

const ll maxN = 2e2 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
pair<ll, ld> a[maxN];


ll _main() {
    while (true) {
        ld down, loan;
        ll duration, j;

        cin >> duration >> down >> loan >> n;
        if (duration < 0) {
            break;
        }

        for (ll i = 1; i <= n; i++) {
            cin >> a[i].F >> a[i].S;
        }

        ld val = (down + loan) * (1 - a[1].S);
        ld monthPay = loan / (ld) duration;
        j = 1;
        ll ans = 0;

        while (val < (loan - (ans * monthPay))) {
            ans++;
            if (ans == a[j + 1].F) {
                j++;
            }
            val = val * (1 - a[j].S);
        }

        
        cout << ans << " month";
        if (ans != 1) {
            cout << 's';
        }
        cout << '\n';
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