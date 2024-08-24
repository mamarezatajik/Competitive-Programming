#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 60;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

ll preSum[maxN];

void pre() {
    ll p = 1, i = 0;
    while (p < 5e16) {
        preSum[i++] = p;
        p *= 2;
    }
    for (ll j = 1; j < i; j++) {
        preSum[j] += preSum[j - 1];
    }
}

ll _main() {
    ll n; cin >> n;
    ll cur, pre, diff;
    ll ans = 0;

    cin >> pre;
    if (n == 1) {
        return cout << 0 << '\n', 0;
    }

    for (ll i = 1; i < n; i++) {
        cin >> cur;
        diff = pre - cur;
        if (diff > 0) {
            auto need = lower_bound(preSum, preSum + 50, diff);
            ans = max(ans, (ll) log2(*need + 1));
        }
        pre = max(cur, pre);
    }

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