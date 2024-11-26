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
vector<ll> a;

bool ok(int i) {
    for (int j = 1; j <= 3; j++) {
        if (i % j == 0 && (i / j) <= 20) {
            return true;
        }
    }
    return i == 50;
}

void pre() {
    for (int i = 0; i <= 60; i++) {
        if (ok(i)) {
            a.push_back(i);
        }
    }
}

ll _main() {
    pre();
    map<ll, pll> ans;
    while (true) {
        cin >> n;
        if (n <= 0) {
            break;
        }

        set<array<ll, 3>> st;
        ll comb = 0, perm = 0;


        if (n <= 180 && !ans.count(n)) {
            for (int i = 0; i < len(a); i++) {
                for (int j = 0; j < len(a); j++) {
                    for (int k = 0; k < len(a); k++) {
                        if (a[i] + a[j] + a[k] == n) {
                            perm++;
                            array<ll, 3> tmp {a[i], a[j], a[k]};
                            sort(all(tmp));
                            st.insert(tmp);
                        }
                    }
                }
            }
            comb = len(st);
        }


        if (ans.count(n)) {
            perm = ans[n].F;
            comb = ans[n].S;
        }
        ans[n] = {perm, comb};

        if (perm == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES ";
            cout << n << " IS " << comb << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES ";
            cout << n << " IS " << perm << ".\n";
        }
        cout << string(70, '*') << '\n';
    }

    return cout << "END OF OUTPUT\n", 0;
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