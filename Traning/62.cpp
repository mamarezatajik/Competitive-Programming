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
string src, dst;

bool is_valid() {
    map<char, ll> cnt;
    n = len(src);
    for (char c: src) {
        cnt[c]++;
    }
    m = 1;
    for (auto [k, v]: cnt) {
        m *= pow(2, v - 1);
    }
    for (char c: dst) {
        cnt[c]--;
    }
    bool ok = true;
    for (auto [k, v]: cnt) {
        ok &= v == 0;
    }
    for (char c: src) {
        cnt[c]++;
    }
    return ok;
}

void solve(string ans, ll src_idx, ll dst_idx, stack<char> stk) {
    if (src_idx == n && dst_idx == n && stk.empty()) {
        cout << ans.substr(0, 4 * n - 1) << '\n';
        return;
    }

    if (src_idx < n) {
        stk.push(src[src_idx]);
        solve(ans + "i ", src_idx + 1, dst_idx, stk);
        stk.pop();
    }

    if (!stk.empty() && dst_idx < n && stk.top() == dst[dst_idx]) {
        stk.pop();
        solve(ans + "o ", src_idx, dst_idx + 1, stk);
    }
}

ll _main() {
    while (cin >> src >> dst) {
        if (!is_valid()) {
            cout << "[\n]" << '\n';
            continue;
        }

        cout << "[\n";
        stack<char> stk;
        solve("", 0, 0, stk);
        cout << "]\n";
    }

    return 0;
}


signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}