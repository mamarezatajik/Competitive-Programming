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


ll a[maxN];


ll _main() {
    string s; cin >> s;
    bool ok = true;

    if (len(s) < 3)
        ok = false;

    else if (s[0] != '1')
        ok = false;
    else if (s[1] != '0')
        ok = false;
    else if (len(s) == 3 && s[2] < '2')
        ok = false;
    else if (len(s) > 3 && s[2] == '0')
        ok = false;

    return cout << (ok ? "YES" : "NO") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}