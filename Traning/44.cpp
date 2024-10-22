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


ll a, b, c, x, y;
set<ll> s;
vector<ll> A(3), B(2);

ll nxt(ll start) {
    for (ll i = 1; start + i <= 52; i++) {
        if (!s.count(start + i)) {
            return start + i;
        }
    }
    return -1;
}


ll _main() {
    while (true) {
        s.clear();
        for (ll i = 1; i <= 3; i++) {
            cin >> A[i - 1];
            s.insert(A[i - 1]);
        }
        for (ll i = 1; i <= 2; i++) {
            cin >> B[i - 1];
            s.insert(B[i - 1]);
        }
        if (A[0] == 0) {
            return 0;
        }

        sort(all(A));
        sort(all(B));

        if (A[0] > B[0]) {
            if (A[2] < B[1]) {
                cout << nxt(A[2]);
            }
            else {
                cout << -1;
            }
        }
        else if (A[2] < B[0]) {
            cout << nxt(0);
        }
        else if (A[1] < B[0]) {
            cout << nxt(A[1]);
        }
        else if (A[0] < B[0]) {
            if (A[2] < B[1]) {
                cout << nxt(A[2]);
            }
            else {
                cout << -1;
            }
        }

        cout << endl;
    }

    return cout << "" << '\n', 0;
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