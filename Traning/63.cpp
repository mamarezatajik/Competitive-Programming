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


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];


ll _main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        map<string, ll> cnt;
        ll mxm = -inf;
        for (ll i = 1; i <= n; i++) {
            vector<ll> tmp (5);
            for (ll j = 0; j < 5; j++) {
                cin >> tmp[j];
            }
            sort(all(tmp));
            string key = "";
            for (ll j = 0; j < 5; j++) {
                key += to_string(tmp[j]) + ',';
            }
            cnt[key]++;
            mxm = max(mxm, cnt[key]);
        }
        ll ans = 0;
        for (auto [k, v]: cnt) {
            if (v == mxm) {
                ans++;
            }
        }
        cout << (ans * mxm) << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}