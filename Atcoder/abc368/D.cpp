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


vector<ll> adj[maxN];
set<ll> mustBe;
ll removes = 0;

bool dfs(ll node, ll parent) {
    ll contain = 0;
    for (ll child : adj[node]) {
        if (child == parent) {
            continue;
        }

        if (!dfs(child, node)) {
            removes++;
        }
        else {
            contain++;
        }
    }

    if (mustBe.count(node) || contain) {
        return true;
    }
    return false;
}


ll _main() {
    ll n, k;
    cin >> n >> k;

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 0; i < k; i++) {
        ll u;
        cin >> u;
        mustBe.insert(u);
    }

    dfs(*mustBe.begin(), *mustBe.begin());

    return cout << (n - removes) << endl, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}