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


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN], b[maxN];


ll _main() {
    cin >> n >> m;
    if (n == 0) {
        exit(0);
    }

    int i, j;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);

    ll ans = 0;
    i = j = 0;
    // i -> dragon;
    // j -> knight;
    bool covered = true;
    while (true) {
        if (j == m) {
            if (i != n) {
                covered = false;
            }
        }
        if (i == n) {
            break;
        }
        if (a[i] <= b[j]) {
            i++;
            ans += b[j];
        }
        j++;
    }

    return cout << (covered ? to_string(ans): "Loowater is doomed!") << '\n', 0;
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