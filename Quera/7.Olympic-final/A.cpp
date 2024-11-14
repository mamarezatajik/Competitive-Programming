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
    string s; 
    cin >> s;
    ll tmp = 0;
    ll cnt = 10;
    ll ans = 0;
    ll ctr = 0, c, num;

    if (s[9] == '?') {
        cnt = 10;
        for (ll i = 0; i <= 8; i++) {
            tmp += (cnt * (s[i] - '0'));
            cnt--;
            cout << s[i];
        }
        c = (tmp + 11) % 11;
        if (c == 0 || c == 1) {
            cout << c << '\n';
        }
        else {
            cout << (11 - c) << '\n';
        }
        return 0;
    }

    for (ll i = 0; i <= 9; i++) {
        cnt = 10;
        tmp = 0;
        for (ll j = 0; j < 9; j++) {
            ll num;
            if (s[j] == '?') {
                num = i;
            }
            else {
                num = s[j] - '0';
            }
            tmp += ((cnt * num) % 11); 
            cnt--;
        }

        c = ((tmp + 11) % 11);
        if (c == 0 || c == 1) {
            if (s[9] == '0' + c) {
                ctr++;
                ans = i;
            } 
        }
        else {
            if ((s[9] - '0') == (11 - c)) {
                ctr++;
                ans = i;
            }
        }
    }

    if (ctr == 0) {
        cout << "cannot be recovered!";
    } 
    else if (ctr != 1) {
        cout << "it's not unique!";
    }
    else {
        for (ll i = 0; i <= 9; i++) {
            if (s[i] == '?') {
                cout << ans;
            }
            else {
                cout << s[i];
            }
        }
    }

    return cout << "" << '\n', 0;
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