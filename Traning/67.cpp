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
    while (scanf("%d", &n) != EOF) {
        priority_queue<ll> pq;
        stack<ll> stk;
        queue<ll> que;
        ll op;
        bool stk_ = true;
        bool que_ = true;
        bool pq_ = true;
        for (ll i = 1; i <= n; i++) {
            cin >> op >> x;
            if (op == 1) {
                que.push(x);
                stk.push(x);
                pq.push(x);
            } else {
                if (stk.empty()) {
                    stk_ = que_ = pq_ = false;
                    continue;
                }
                stk_ &= stk.top()   == x;
                que_ &= que.front() == x;
                pq_  &= pq.top()    == x;
                stk.pop();
                que.pop();
                pq.pop();
            }
        }
        ll cnt = stk_ + que_ + pq_;
        if (cnt == 0) {
            cout << "impossible";
        } else if (cnt > 1) {
            cout << "not sure";
        } else {
            if (stk_) {
                cout << "stack";
            } else if (que_) {
                cout << "queue";
            } else {
                cout << "priority queue";
            }
        }
        cout << '\n';
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