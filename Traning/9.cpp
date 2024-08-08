#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll vis[maxN], isBipartite, color[maxN] = { 0 };
vector<ll> adj[maxN], Pari, Arya;

void dfs(ll node, ll myColor) {
    color[node] = myColor;
    for (ll child : adj[node]) {
        if (color[child] == 0)
            dfs(child, -myColor);
        if (color[child] == myColor)
            isBipartite = false;
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
    }

    isBipartite = true;
    for (ll i = 0; i < n; i++) 
        if (color[i] == 0)
            dfs(i, 1);

    if (!isBipartite)
        return cout << -1, 0;

    for (ll i = 0; i < n; i++) {
        if (color[i] == 1)
            Pari.push_back(i + 1);
        else
            Arya.push_back(i + 1);
    }

    cout << len(Pari) << '\n';
    for (ll node : Pari)
        cout << node << ' ';
    cout << '\n';

    cout << len(Arya) << '\n';
    for (ll node : Arya)
        cout << node << ' ';

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