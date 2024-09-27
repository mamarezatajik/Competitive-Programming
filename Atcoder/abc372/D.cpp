#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], ans[maxN];


ll _main() {
    ll n; cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ans[n - 1] = 0;
    if (n != 1) {
        ans[n - 2] = a[n - 1] > a[n - 2];
    }
    ll cnt = 1;
    for (ll i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        if (i != 0) {
            ans[i - 1] = cnt;
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }


    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}