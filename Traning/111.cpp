#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;




ll _main() {
    ll n;
    cin >> n;
    if (n == 0) {
        exit(0);
    }

    vector<ll> a(n);
    bool first = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!first && a[i]) {
            cout << ' ' << a[i];
        }
        if (first && a[i]) {
            cout << a[i];
            first = false;
        }
    }
    if (*max_element(all(a)) == 0) {
        cout << 0;
    }

    cout << '\n';
    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc) {
        _main();
    }
    return 0;
}