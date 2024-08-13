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


ll a[maxN], ps[maxN];


ll _main() {
    ll n; cin >> n;
    for (ll i = 0; i <= n; i++) 
        ps[i] = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    string s; cin >> s;
    vector<ll> ls, rs;

    for (ll i = 0; i < n; i++) 
        if (s[i] == 'L')
            ls.push_back(i);

    for (ll i = n - 1; i >= 0; i--)
        if (s[i] == 'R')
            rs.push_back(i);

    ll ans = 0;
    for (ll i = 0; i < min(len(ls), len(rs)); i++)
        if (rs[i] > ls[i])
            ans += ps[rs[i] + 1] - ps[ls[i]];

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}