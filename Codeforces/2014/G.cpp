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


ll a[maxN], d[maxN];

ll _main() {
    ll n, m, k;
    cin >> n >> m >> k;

    for (ll i = 0; i < n; i++) {
        cin >> d[i] >> a[i];
    }

    stack<pll> stk; // {expire day, rem}
    ll cnt, need, tot;
    ll today = 1, ans = 0;

    for (ll i = 0; i < n; i++) {
        stk.push({d[i] + k, a[i]});

        cnt = 0;
        while (!stk.empty()) {
            auto [expire, rem] = stk.top();
            stk.pop();
            if (expire <= today) {
                stk = stack<pll>();
                break;
            }

            rem += cnt;
            tot = rem / m;
            if (tot > expire - today) {
                ans += expire - today;
                break;
            }
            else {
                ans += tot;
                today += tot;
            }
            cnt = rem % m;
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