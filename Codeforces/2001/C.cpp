#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1000 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll parent[maxN];

ll query(ll a, ll b) {
    ll x;
    cout << "? " << a << ' ' << b << endl;
    cin >> x;
    return x;
}

ll findParent(ll a) {
    ll b = 1, x;
    while (true) {
        x = query(a, b);
        if (x == a) {
            return b;
        }
        b = x;
    }
    return 1;
}


ll _main() {
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
        parent[i] = findParent(i);
    }

    cout << '!';
    for (ll i = 2; i <= n; i++) {
        cout << ' ' << parent[i] << ' ' << i;
    }
    cout << endl;

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