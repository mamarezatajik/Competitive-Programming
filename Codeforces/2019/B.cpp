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

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], b[maxN];


ll _main() {
    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = n - 1 + i * (n - i - 1);
    }

    map<ll, vector<pll>> vals;
    ll val;
    if (a[0] != 1) {
        vals[0].push_back({1, a[0] - 1});
    }
    for (ll i = 0; i < n; i++) {
        vals[b[i]].push_back({a[i], a[i]});
        if (0 < i && a[i] - 1 != a[i - 1]) {
            val = b[i] - (n - i - 1);
            vals[val].push_back({a[i - 1] + 1, a[i] - 1});
        }
    }

    map<ll, ll> ans;
    for (ll i = 0; i < q; i++) {
        ll k;
        cin >> k;
        if (ans.count(k)) {
            cout << ans[k] << ' ';
            continue;
        }

        ll qu = 0;
        for (auto [l, r]: vals[k]) {
            qu += r - l + 1;
        }
        ans[k] = qu;
        cout << ans[k] << ' ';
    }

    return cout << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}