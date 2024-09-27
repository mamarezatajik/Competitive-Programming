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


ll _main() {
    ll m;
    cin >> m;

    vector<ll> ans;
    while (m != 0) {
        ll ctr = 1;
        ll cnt = 0;
        while (ctr <= m) {
            ctr *= 3;
            cnt++;
        } ctr /= 3;
        m -= ctr;
        ans.push_back(cnt - 1);
    }

    cout << len(ans) << '\n';
    for (ll i = 0; i < len(ans); i++) {
        cout << ans[i] << ' ';
    }


    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}