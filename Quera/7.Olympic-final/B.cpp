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


ld p[4];


ll _main() {
    ll j, k;
    cin >> k >> j;
    if (k > j) {
        swap(k, j);
        cin >> p[2] >> p[1];
    }
    else {
        cin >> p[1] >> p[2]; // (k < j)
    }
    cin >> p[3];

    ll diff = j - k;
    ll ans = 0;

    if ((p[2] / 2.0) > p[3]) {
        cout << j * p[3] << '\n';
        return 0;
    }

    ans += (diff / 2) * p[2];
    if (diff % 2 == 1) {
        diff = 1;
        j = k + 1;
    }
    else {
        diff = 0;
        j = k;
    }

    if (diff != 1 && ((p[1] + p[2]) / 2.0) > p[3]) {
        cout << ans + j * p[3] << '\n';
        return 0;
    }

    ll jj = 0, kk = 0;
    if (diff == 1) {
        jj = j;
        kk = k;
        k = j = (k / 2) * 2;
        jj -= j;
        kk -= k;
    }

    if ((p[1] + p[2]) / 2.0 < p[3]) {
        ans += (j / 2) * (p[1] + p[2]);
    }
    else {
        ans += j * p[3];
    }

    if (kk == 0 && jj == 0) {
        return cout << ans << '\n', 0;
    }

    if (kk == 0) { // jj = 1
        ans += min(p[2], p[3]);
    }
    if (kk == 1) { // jj = 2
        ans += min({
            p[1] + p[2],
            p[3] + p[2],
            p[3] + p[3]
        });
    }

    return cout << ans << '\n', 0;
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