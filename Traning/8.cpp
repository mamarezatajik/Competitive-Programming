#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 5e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll vis[maxN] = {false}, cnt;
vector<ll> adj[maxN], scc[maxN];
map<ll, ll> rev;

void dfs(ll node) {
    vis[node] = true;
    scc[cnt].push_back(node);
    rev[node] = cnt;
    for (ll child : adj[node]) {
        if (!vis[child]) {
            dfs(child);
        } 
    }
}


ll _main() {
    ll n, m, k, u, v; 
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        cin >> k;
        if (k) {
            cin >> u;
            u--;
        }
        for (ll i = 1; i < k; i++) {
            cin >> v; 
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    for (ll i = 0; i < n; i++) 
        cout << len(scc[rev[i]]) << ' ';


    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}