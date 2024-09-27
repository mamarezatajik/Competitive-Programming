#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], px[maxN], hsh[1000010];


ll _main() {
    ll n, q;
    cin >> n >> q;
    px[0] = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        px[i + 1] = px[i] ^ hsh[a[i]];
    }

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        cout << (px[r] == px[l - 1] ? "YES" : "NO") << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for (ll i = 0; i < 1000010; i++) {
        hsh[i] = rng();
    }

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}