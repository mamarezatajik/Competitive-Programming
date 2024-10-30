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

const ll maxN = 2e3 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
char big[maxN][maxN], small[maxN][maxN], tmp[maxN][maxN];


void rotate() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            tmp[j][m - i - 1] = small[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            small[i][j] = tmp[i][j];
        }
    }
}

ll equal() {
    ll ans = 0;
    for (ll i = 0; i + u < n; i++) {
        for (ll j = 0; j + v < n; j++) {
            bool ok = true;
            for (ll u = 0; u < m; u++) {
                for (ll v = 0; v < m; v++) {
                    if (big[i + u][j + v] != small[u][v]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                ans++;
            }
        }
    }
    return ans;
}

ll _main() {
    while (true) {
        cin >> n >> m;
        if (n == 0) {
            break;
        }
        for (ll i = 0; i < n; i++) {
            string s; cin >> s;
            for (ll j = 0; j < n; j++) {
                big[i][j] = s[j];
            }
        }


        for (ll i = 0; i < m; i++) {
            string s; cin >> s;
            for (ll j = 0; j < m; j++) {
                small[i][j] = s[j];
            }
        }

        cout << (equal()) << ' ';
        rotate();
        cout << (equal()) << ' ';
        rotate();
        cout << (equal()) << ' ';
        rotate();
        cout << (equal()) << '\n';
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