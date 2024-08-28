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


ll query(ll a, ll b) {
    cout << "? " << a << ' ' << b << endl;
    ll x;   cin >> x;   return x;
}


ll _main() {
    ll l = 2, r = 999;
    ll a, b;

    while (l < r) {
        a = (2 * l + r) / 3;
        b = (2 * r + l) / 3;
        ll x = query(a, b);
        if (x == a * b) {
            l = b + 1;
        }
        else if (x == (a + 1) * (b + 1)) {
            r = a;
        }
        else {
            l = a + 1;
            r = b;
        } 
    }

    cout << "! ";
    return cout << r << endl, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}