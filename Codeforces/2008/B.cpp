#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll _main() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    if ((ll) sqrt(n) * (ll) sqrt(n) != n) {
        return cout << "No\n", 0;
    }

    n = sqrt(n);

    vector<vector<char>> a (n, vector<char>(n, '1'));
    ll k = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            a[i][j] = s[k];
            k++;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 ||
                j == 0 || j == n - 1) {
                    if (a[i][j] == '0') {
                        return cout << "No\n", 0;
                    }
                }
            else {
                if (a[i][j] == '1') {
                    return cout << "No\n", 0;
                }
            }
        }
    }


    return cout << "Yes" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}