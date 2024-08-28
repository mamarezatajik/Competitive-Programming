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
    ll res;
    cout << "? " << a << ' ' << b << endl;
    cin >> res;
    return res;
}


ll _main() {
    ll a = 2, b = 999, mid;

    while (a < b) {
        mid = (a + b) / 2;
        if (query(mid, mid) > mid * mid) {
            b = mid;
        }
        else {
            a = mid + 1;
        }
    }

    cout << "! ";
    return cout << ((a + b) / 2) << endl, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}