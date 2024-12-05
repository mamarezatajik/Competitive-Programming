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


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll M[10][10];


ll _main() {
    cin >> n;
    vector<ll> p (n);
    iota(all(p), 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    ll aliceVal = inf;
    do {
        ll bobVal = 0;
        vector<bool> used (n, false);
        for (int i = 0; i < n; i++) { // p[i] shows row number that alice cutted;
            ll idx = -1;
            ll val = inf;
            for (int j = 0; j < n; j++) { // j shows the best choice of bob;
                if (used[j]) {
                    continue;
                }
                if (val > M[p[i]][j]) {
                    val = M[p[i]][j];
                    idx = j;
                }
            }
            used[idx] = true;
            bobVal += val;
        }
        aliceVal = min(aliceVal, bobVal);
    } while (next_permutation(all(p)));

    return cout << aliceVal << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}