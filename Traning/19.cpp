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


ll a[maxN];

ll find_mex(vector<ll> seq) {
    ll ans = 0;
    for (ll i = 0; i < len(seq); i++) {
        if (seq[i] == ans) {
            ans++;
        }
        else if (i == 0) {
            break;
        }
        else if (seq[i] == seq[i - 1]) {
            continue;
        }
        else {
            break;
        }
    }
    return ans;
}

ll mex() {
    ll l;
    cin >> l;
    vector<ll> seq (l);
    for (ll i = 0; i < l; i++) {
        cin >> seq[i];
    }
    sort(all(seq));

    seq.push_back(find_mex(seq));
    sort(all(seq));

    return find_mex(seq);
}


ll _main() {
    ll n, m, mx = 0;
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        mx = max(mx, mex());
    }

    ll ans = mx * (min(m, mx) + 1);
    if (m > mx) {
        ans += (m + mx + 1) * (m - mx) / 2;
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