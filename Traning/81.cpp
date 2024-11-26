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

const ll maxN = 1e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, s, ctr = 1;
ll a[maxN], b[maxN];


ll _main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        cout << "Case " << ctr++ << ":\n";

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } sort(a, a + n);


        k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                b[k++] = a[i] + a[j];
            }
        }
        sort(b, b + k);

        cin >> m;
        while (m--) {
            cin >> s;
            cout << "Closest sum to " << s << " is ";
            ll diff = inf, idx = -1;
            for (int i = 0; i < k; i++) {
                if (diff > abs(b[i] - s)) {
                    diff = abs(b[i] - s);
                    idx = i;
                }
            }

            cout << b[idx] << ".\n";
        }
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