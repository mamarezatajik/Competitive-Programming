#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;
typedef pair<pll, ll>       ppl;

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
    ll Q_num, Period;
    priority_queue<ppl, vector<ppl>, greater<ppl>> pq;
    while (true) {
        cin >> s;
        if (s == "#") {
            break;
        }
        cin >> Q_num >> Period;
        pq.push({{Period, Q_num}, Period});
    }

    cin >> k;
    while (k--) {
        auto [tmp, period] = pq.top();
        auto [time, q_num] = tmp;

        cout << q_num << '\n';
        pq.pop();
        pq.push({{time + period, q_num}, period});
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