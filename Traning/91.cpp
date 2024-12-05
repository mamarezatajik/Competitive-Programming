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


ll _main() {
    map<char, vector<ll>> mp;
    string s;
    cin >> s;
    n = len(s);

    for (int i = 0; i < n; i++) {
        mp[s[i]].push_back(i);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        mp[c].push_back(n);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        mp[c].push_back(n);
    }

    cin >> q;
    while (q--) {
        cin >> s;
        m = len(s);

        ll idx = 0; l = -1;
        bool found = true;
        for (int i = 0; i < m; i++) {
            if (l == -1) {
                l = *lower_bound(all(mp[s[i]]), idx);
            }
            r = *lower_bound(all(mp[s[i]]), idx);
            if (r == n) {
                cout << "Not matched\n";
                found = false;
                break;
            }
            idx = r + 1;
        }

        if (found) {
            cout << "Matched " << l << ' ' << r << '\n';
        }
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}