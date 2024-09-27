#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], n, c, dp[maxN][2];
vector<ll> adj[maxN];

void dfs(ll node, ll parent) {
    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node);
        dp[node][0] += max(dp[child][0], dp[child][1]);
        dp[node][1] += max(dp[child][0], dp[child][1] - 2 * c);
    }
}


ll _main() {
    cin >> n >> c;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][0] = 0;
        dp[i][1] = a[i];
        adj[i].clear();
    }

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);

    return cout << max(dp[0][0], dp[0][1]) << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}