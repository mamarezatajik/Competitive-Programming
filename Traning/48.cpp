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

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, u, v, w, x, y, z, l, r;
ll p[maxN], q[maxN], cnt = 1, psp[maxN], psq[maxN];


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
        psp[i] = psp[i - 1] + p[i];
    } 

    for (ll i = 1; i <= n; i++) {
        cin >> q[i];
        psq[i] = psq[i - 1] + q[i];
    } 

    cout << "Case " << cnt++ << ": ";
    if (psq[n] > psp[n]) {
        return cout << "Not possible\n", 0;
    }

    l = 1, r = 1;
    ll sum_p, sum_q;
    while (r <= n) {
        if (r < l || p[r] >= q[r]) {
            r++;
            continue;
        }
        sum_p = psp[r] - psp[l - 1];
        sum_q = psq[r] - psq[l - 1];
        if (sum_p >= sum_q) {
            r++;
        }
        else {
            l++;
        }
    }   

    return cout << "Possible from station " << l << '\n', 0;
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