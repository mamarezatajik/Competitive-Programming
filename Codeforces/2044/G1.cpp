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

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll vis[maxN], par[maxN], dp[maxN], cycle[maxN];


ll _main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vis[i] = false;
        par[i] = x - 1;
        dp[i] = 0;
        cycle[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ll cnt = 0;
            ll cur = i;
            vector<ll> notSeen;
            while (!vis[cur]) {
                vis[cur] = true;
                notSeen.push_back(cur);
                cur = par[cur];
                cnt++;
            }
            for (ll idx: notSeen) {
                vis[idx] = false;
            }
            ll curCycle = cur;
            while (!vis[curCycle]) {
                vis[curCycle] = true;
                cycle[curCycle] = true;
                dp[curCycle] = -inf;
                curCycle = par[curCycle];
            }


            // we found the cycle;
            // now use dp;
            if (cycle[i]) {
                continue;
            }
            cur = i;
            cnt = 0;
            while (!cycle[cur] && !vis[cur]) {
                cur = par[cur];
                cnt++;
            }
            if (!cycle[cur] && vis[cur]) {
                cnt += dp[cur];
            }
            cur = i;
            while (!cycle[cur] && !vis[cur]) {
                vis[cur] = true;
                dp[cur] = cnt--;
                cur = par[cur];
            }
        }
    }


    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    return cout << (ans + 2) << '\n', 0;
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