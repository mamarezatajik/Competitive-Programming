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
    ll l, r; cin >> l >> r;
    ll L, R; cin >> L >> R;

    ll ans = 1;

    if (r < L || R < l)
        ans = 1;
    else if (l == L && r == R)
        ans = r - l;
    else if (r == R)
        ans = r - max(l, L) + 1;
    else if (l == L)
        ans = min(r, R) - l + 1;
    // else if (L < l && r < R)
    //     ans = r - l + 2;
    // else if (l < L && R < r)
    //     ans = R - L + 2;
    else
        ans = min(r, R) - max(l, L) + 2;


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