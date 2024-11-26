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


ll _main() {
    cin >> n;

    vector<vector<char>> a (50, vector<char>(50, '.'));

    for (int i = 0; i < 50; i++) {
        for (int j = 1; j < 50; j += 3) {
            a[i][j] = 'X';
        }
    }

    for (ll i = 1; i < 49; i += 2) {
        for (ll j = 0; j < 50; j += 2) {
            if (n != 0) {
                a[i][j] = '.';
                n--;
            }
        }
    }

    for (ll i = 0; i < 50; i++) {
        for (ll j = 0; j < 50; j++) {
            cout << a[i][j];
        } cout << '\n';
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