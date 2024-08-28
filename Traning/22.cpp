#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 500 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


string a[maxN];
ll n, m, k, s;
set<pll> visited;


void dfs(ll i, ll j) {
    if (k == s || visited.count({i, j})) {
        return;
    }

    s--;
    visited.insert({i, j});

    // next neighbor :
    if (0 < j && a[i][j - 1] == '.') {
        dfs(i, j - 1);
    }
    if (j < (m - 1) && a[i][j + 1] == '.') {
        dfs(i, j + 1);
    }
    if (0 < i && a[i - 1][j] == '.') {
        dfs(i - 1, j);
    }
    if (i < (n - 1) && a[i + 1][j] == '.') {
        dfs(i + 1, j);
    }
}


ll _main() {
    visited.clear();
    cin >> n >> m >> k;
    s = 0;
    ll x = -1, y = -1;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        for (ll j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                s++;
                if (x == -1) {
                    x = i;
                    y = j;
                }
            }
        }
    }

    dfs(x, y);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (a[i][j] == '.' && 
                !visited.count({i, j}))
                    cout << 'X';
            else
                cout << a[i][j];
        }
        cout << '\n';
    }


    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}