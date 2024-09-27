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
    ll n, k; 
    cin >> n >> k;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] >= k) {
            cnt += a[i];
        }
        else if (a[i] == 0 && cnt > 0) {
            cnt--;
            ans++;
        }
    }


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