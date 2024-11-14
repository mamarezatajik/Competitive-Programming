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


ll n, m, k, q, u, v, w, x, y, z, l, r, ctr = 1;
string s;

ll _main() {
    while (cin >> s) {
        if (s == "end") {
            break;
        }

        n = len(s);
        vector<stack<char>> ans (1, stack<char>());
        ans[0].push(s[0]);
        for (ll i = 1; i < n; i++) {
            bool found = false;
            for (ll j = 0; j < len(ans); j++) {
                if (!found && s[i] <= ans[j].top()) {
                    ans[j].push(s[i]);
                    found = true;
                }
            }
            if (!found) {
                ans.push_back(stack<char>());
                ans.back().push(s[i]);
            }
        }

        cout << "Case " << ctr++ << ": " << len(ans) << '\n';
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