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
    cin >> n;
    string s;
    cin >> s;

    set<ll> zero, one;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero.insert(i);
        }
        else {
            one.insert(i);
        }
    }

    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ll last_zero = -1;
        if (len(zero)) {
            last_zero = *(prev(zero.end()));
        }
        while (len(zero) && last_zero >= i) {
            zero.erase(last_zero);
            last_zero = -1;
            if (len(zero)) {
                last_zero = *(prev(zero.end()));
            }
        }

        ll first_one = -1;
        if (len(one)) {
            first_one = *one.begin();
        }
        if (first_one >= i) {
            first_one = -1;
            one.clear();
        }

        if (s[i] == '1' &&
            last_zero != -1) {
                zero.erase(last_zero);
        }
        else if (s[i] == '1' && 
            first_one != -1) {
                one.erase(first_one);
        }
        else {
            ans += i + 1;
        }
    }

    return cout << ans << '\n', 0;
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