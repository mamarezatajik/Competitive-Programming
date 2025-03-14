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
    string s;
    cin >> s;
    n = len(s);

    vector<int> num (4, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] <= '3') {
            num[s[i] - '0']++;
        }
        sum += s[i] - '0';
        if (sum >= 10) {
            sum = sum / 10 + sum % 10;
        }
    }

    ll need = 9 - sum;
    bool ok;
    if (need == 0 || need == 9) {
        ok = true;
    }
    else if (need == 1 && (num[2] >= 5 || (num[3] >= 1 && num[2] >= 2))) {
        ok = true;
    }
    else if (need == 2 && num[2]) {
        ok = true;
    }
    else if (need == 3 && (num[2] >= 6 || num[3] >= 2 || (num[2] >= 3 && num[3] >= 1))) {
        ok = true;
    }
    else if (need == 4 && num[2] >= 2) {
        ok = true;
    }
    else if (need == 5 && (num[2] >= 7 || (num[2] >= 1 && num[3] >= 2) || (num[2] >= 4 && num[3] >= 1))) {
        ok = true;
    }
    else if (need == 6 && (num[3] >= 1 || num[2] >= 3)) {
        ok = true;
    }
    else if (need == 7 && (num[2] >= 8 || (num[2] >= 2 && num[3] >= 2) || (num[2] >= 5 && num[3] >= 1))) {
        ok = true;
    }
    else if (need == 8 && ((num[2] >= 1 && num[3] >= 1) || num[2] >= 4)) {
        ok = true;
    }
    else {
        ok = false;
    }

    return cout << (ok ? "YES": "NO") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}