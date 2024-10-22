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


ll _main() {
    vector<pair<string, string>> s;
    while (true) {
        string t, g;
        cin >> t;
        if (t == "#") {
            break;
        }
        s.push_back({"", t});
        for (ll i = 0; i <= len(t) - 1; i++) {
            g.push_back(tolower(t[i]));
        }
        sort(all(g));
        s.back().F = g;
    }

    sort(all(s));
    vector<string> ans;

    for (ll i = 0; i < len(s); i++) {
        if (i == 0) {
            if (i + 1 < len(s) && s[i + 1].F != s[i].F) {
                ans.push_back(s[i].S);
            }
        }
        else if (i == len(s) - 1) {
            if (s[i - 1].F != s[i].F) {
                ans.push_back(s[i].S);
            }
        }
        else {
            if (s[i - 1].F != s[i].F && s[i].F != s[i + 1].F) {
                ans.push_back(s[i].S);
            }
        }
    }

    sort(all(ans));
    for (string g: ans) {
        cout << g << '\n';
    }

    return 0;
}


signed main() {
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}