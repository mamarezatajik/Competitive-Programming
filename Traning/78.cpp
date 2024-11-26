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

const ll maxN = 1e4 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, q, p;
ll l[maxN], r[maxN];
string s[maxN];


ll _main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> l[i] >> r[i];
    }

    cin >> q;
    while (q--) {
        cin >> p;

        string ans = "";
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] <= p && p <= r[i]) {
                cnt++;
                if (ans == s[i]) {
                    cnt--;
                }
                ans = s[i];
            }
        }

        if (cnt == 1) {
            cout << ans;
        } else {
            cout << "UNDETERMINED";
        } cout << endl;
    }

    return 0;
}


signed main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
        if (tc) {
            cout << endl;
        }
    }
    return 0;
}