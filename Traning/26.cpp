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


ll arr[maxN], cost[maxN], id[maxN];


ll _main() {
    ll n, m; 
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
        id[i] = i;
    }

    sort(id, id + n, [&](const ll x, const ll y) {
        return arr[x] < arr[y];
    });

    ll ans = 0, diff;
    ll cur, val, pre;
    ll a, b, x, y, nxt;

    for (ll i = 0; i < n; i++) {
        a = cost[id[i]];
        x = arr[id[i]];
        if (i + 1 < n) {
            b = cost[id[i + 1]];
            y = arr[id[i + 1]];
        }

        cur = min(m / x, a) * x;
        a = min(m / x, a);
        ans = max(ans, cur);

        if (x >= m) {
            break;
        }

        if (i + 1 < n && x + 1 == y) {
            diff = m - cur;
            nxt = min(diff / y, b) * y;
            b -= min(diff / y, b);
            diff = m - cur - nxt;
            val = min({a, b, diff});
            ans = max(ans, cur + nxt + val);
        }
    }

    cout << ans << '\n';

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }

    return 0;
}