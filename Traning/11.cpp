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

ll _main() {
    ll n; cin >> n;
    string s; cin >> s;
    unordered_map<ll, ll> m;
    m[0] = 1;

    ll preSum = 0, ans = 0, length;
    for (ll i = 0; i < n; i++) {
        preSum += (s[i] - '0');
        length = preSum - i - 1;
        ans += m[length];
        m[length]++;
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