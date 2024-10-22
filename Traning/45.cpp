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

const ll maxN = 500 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, cnt = 1;
char a[maxN][maxN];


ll _main() {
    string s, t = "";
    getline(cin, s);

    n = len(s);

    for (ll i = 0; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            t += s[i];
        }
    }

    n = len(t);
    cout << "Case #" << cnt++ << ":\n";
    if ((ll) sqrt(n) * (ll) sqrt(n) != n) {
        return cout << "No magic :(\n", 0;
    }

    n = sqrt(n); ll k = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            a[i][j] = t[k++];
        }
    }

    bool ok = true;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[i][j] != a[j][i] ||
                a[i][j] != a[n - i - 1][n - j - 1] ||
                a[n - i - 1][n - j - 1] != a[n - j - 1][n - i - 1]) {
                    ok = false;
            }
        }
    }

    if (ok) {
        cout << n;
    }
    else {
        cout << "No magic :(";
    }

    return cout << '\n', 0;
}


signed main() {
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    char c = getchar();

    while (tc--) {
        _main();
    }

    return 0;
}