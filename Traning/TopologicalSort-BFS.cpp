#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(cnt)              (ll) (cnt.size())
#define all(cnt)              (cnt).begin(), (cnt).end()

const ll maxN = 3e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll inDegree[maxN], dp[maxN], ans;
vector<ll> adj[maxN], topo;
string s;


ll _main() {
    ll n, m; 
    cin >> n >> m;
    cin >> s;

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<ll> q;
    for (ll u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    ll cnt = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop(); 
        cnt++;
        topo.push_back(u);

        for (ll v: adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (cnt < n) {
        return cout << -1, 0;
    }

    ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        fill(dp, dp + n, 0ll);
        for (ll u: topo) {
            if (s[u] == c) {
                dp[u]++;
            }
            for (ll v: adj[u]) {
                dp[v] = max(dp[u], dp[v]);
            }
            ans = max(ans, dp[u]);
        }
    }

    cout << ans;

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}