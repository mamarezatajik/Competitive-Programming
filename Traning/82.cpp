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

const ll maxN = 2e4 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll f, r;
ld a[maxN], b[maxN], d[maxN];


ll _main() {
    while (true) {
        cin >> f;
        if (f == 0) {
            break;
        } cin >> r;

        for (int i = 0; i < f; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < r; i++) {
            cin >> b[i];
        }

        ll k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < f; j++) {
                d[k++] = b[i] / a[j]; 
            }
        }
        sort(d, d + k);

        ld ans = -inf;
        for (int i = 1; i < k; i++) {
            ans = max(ans, d[i] / d[i - 1]);
        }

        cout << fixed << setprecision(2) << ans << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}