#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 100;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll k, sequence[maxN], preSum[maxN] = { 0 };

void fibonacci() {
    for (ll i = 0; i < maxN - 1; i++) {
        if (i < k)
            sequence[i] = 1;
        else
            sequence[i] = (sequence[i - 1] + sequence[i - k]) % mod;
        preSum[i + 1] = (preSum[i] + sequence[i]) % mod;
    }
}


ll _main() {
    ll a, b;
    cin >> a >> b;

    ll ans = preSum[b + 1] - preSum[a];
    if (ans < 0)
        ans += mod;

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc >> k;
    fibonacci();
    while (tc--)
        _main();

    return 0;
}