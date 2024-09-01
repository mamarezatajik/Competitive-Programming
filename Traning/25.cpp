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


ll arr[maxN];


ll _main() {
    ll n, a, b; 
    cin >> n >> a >> b;

    ll g = gcd(a, b);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= g;
    }

    sort(arr, arr + n);

    ll mx = arr[n - 1];
    ll ans = mx - arr[0];
    for (ll i = 0; i < n - 1; i++) {
        mx = arr[i] + g;
        ans = min(ans, mx - arr[i + 1]);
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