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


ll vis[maxN] = { 0 }, isReasonable;
vector<ll> adj[maxN];
set<pll> edges;


void dfs(ll node, ll parent) {
    vis[node] = true;

    for (ll child : adj[node]) {
        if (child == parent)
            continue;

        if (parent != -1 && !edges.count({
            max(child, parent), min(child, parent) }))
                isReasonable = false;

        if (!vis[child])
            dfs(child, node);
    }
}

ll _main() {
    ll n, m, u, v;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({
            max(u, v), min(u, v)
        });
    }

    isReasonable = true;
    for (ll i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, -1);

    for (ll i = 0; i < n; i++) 
        vis[i] = false;

    for (ll i = n - 1; i >= 0; i--)
        if (!vis[i])
            dfs(i, -1);

    return cout << (isReasonable ? "YES" : "NO"), 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}