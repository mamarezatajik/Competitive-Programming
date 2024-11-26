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
    ll k;
    while (cin >> k) {
        vector<string> ans;

        string strK = to_string(k);
        string base = "1/";
        base += strK;
        base += " = 1/";

        for (int y = k + 1; y <= 2 * k; y++) {
            ll x;
            if (y * k % (y - k) == 0) {
                x = y * k / (y - k);
            } else {
                continue;
            }

            string query = "";
            string strX = to_string(x);
            string strY = to_string(y);

            query += strX;
            query += " + 1/";
            query += strY;

            ans.push_back(base + query);
        }

        cout << len(ans) << '\n';
        for (string s: ans) {
            cout << s << '\n';
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