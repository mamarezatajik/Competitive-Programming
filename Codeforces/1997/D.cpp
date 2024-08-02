#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io             ios_base::sync_with_stdio(false);\
                                cin.tie(0); cout.tie(0)
#define print(n)            cout << (n) << '\n'
#define print_vec(arr)      for (auto __ : arr)\
                                cout << __ << ' '; cout << '\n'
#define print_vec_vec(arr)  for (auto _ : arr)\
                                {print_vec(_);}; cout << '\n'
#define all(arr)            arr.begin(), arr.end()
#define rall(arr)           arr.rbegin(), arr.rend()
#define len(arr)            (ll) (arr.size())
template<class T>
#define indexed_set         tree<T, null_type,less<T>,\
                                rb_tree_tag,\
                                tree_order_statistics_node_update>
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


const ll mod = 1e9 + 7;
const ll inf = LONG_LONG_MAX;


vector<vector<ll>> adj;
vector<ll> cost;

ll dfs(ll node, ll parent) {
    ll avgCost, minChildCost = inf;
    for (ll child : adj[node]) {
        if (child == parent)
            continue;
        minChildCost = min(minChildCost, dfs(child, node));
    }
    avgCost = (cost[node] + minChildCost) / 2;
    if (minChildCost < cost[node])
        avgCost = minChildCost;
    if (minChildCost == inf)
        avgCost = cost[node];
    return avgCost;
}

ll solve(ll root) {
    ll minChildCost, ans = inf;
    for (ll child : adj[root]) {
        minChildCost = dfs(child, root);
        ans = min(ans, minChildCost);
    }
    return ans + cost[root];
}

ll _main() {
    ll n; cin >> n;
    adj.clear(); adj.resize(n, vector<ll>());
    cost.clear(); cost.resize(n);

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 1; i < n; i++) {
        ll p; cin >> p; p--;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    return print(solve(0)), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}