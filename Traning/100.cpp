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
const ll inf  = 1e8 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


bool check() {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        int j = i;
        ll sum = 0;
        for (; j - i < x && j < n; j++) {
            if (sum + a[j] <= x) {
                sum += a[j];
            } else {
                break;
            }
        }
        if (sum == 0) {
            return false;
        }
        i = j - 1;
    }

    return cnt <= m;
}


ll _main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        l = 1, r = inf;
        while (l < r) {
            x = (l + r) / 2;
            if (check()) {
                r = x;
            } else {
                l = x + 1;
            }
        }

        cout << r << endl;
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