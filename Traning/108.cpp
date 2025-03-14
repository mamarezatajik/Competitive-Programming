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

const ll maxN = 1e4 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;


ll _main() {
    while (cin >> n && n != 0) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } 
        sort(all(a));

        ll sum = 1, mx = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                sum++;
            } else {
                mx = max(mx, sum);
                sum = 1;
            }
        }
        mx = max(sum, mx);

        cout << mx << '\n';
        for (int i = 0; i < mx; i++) {
            for (int j = i; j < n; j += mx) {
                if (j != i) {
                    cout << ' ';
                }
                cout << a[j];
            }
            cout << '\n';
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