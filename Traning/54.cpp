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
    ll s, b;
    while (true) {
        cin >> s >> b;
        if (s == 0) {
            break;
        }

        set<ll> st;
        for (ll i = 1; i <= s; i++) {
            st.insert(i);
        } 

        while (b--) {
            cin >> l >> r;
            for (ll i = l; i <= r; i++) {
                st.erase(i);
            }

            auto L = st.upper_bound(l);
            if (L != st.begin()) {
                u = *(prev(L));
            } else {
                u = -1;
            }
            auto R = st.upper_bound(r);
            if (R != st.end()) {
                v = *(R);
            } else {
                v = -1;
            }

            if (u == -1) {
                cout << "* ";
            } else {
                cout << u << ' ';
            }
            if (v == -1) {
                cout << "*\n";
            } else {
                cout << v << '\n';
            }
        }
        cout << "-\n";
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