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


ll p[maxN];


ll _main() {
    ll n; cin >> n;

    if (n % 2 == 0)
        return cout << -1 << '\n', 0;

    ll i = 0, j = n - 1, ctr = 1;
    while (i <= j) {
        p[i++] = ctr++;
        if (i > j)
            break;
        p[j--] = ctr++;
    }

    for (ll i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}