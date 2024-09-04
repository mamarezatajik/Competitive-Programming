#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


vector<ll> a(maxN);


void pre() {
    ll ctr = a[0] = 1;
    for (ll i = 1; i < maxN; i++) {
        a[i] = a[i - 1] + ctr++;
    }
}


ll _main() {
    ll l, r;
    cin >> l >> r;

    ll n = r - l + 1;
    ll ans = upper_bound(all(a), n) - a.begin();


    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    pre();
    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}