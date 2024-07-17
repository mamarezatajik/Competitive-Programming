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
#define Max(arr)            *max_element(all(arr))
#define Min(arr)            *min_element(all(arr))
#define Sum(arr)            accumulate(all(arr), 0ll)
#define indexed_set         tree<ll, null_type,less<ll>,\
                                rb_tree_tag,\
                                tree_order_statistics_node_update>
#define ll_max              LONG_LONG_MAX
#define ll_min              LONG_LONG_MIN
#define vec                 vector
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


ll mod = 1e9 + 7;

vec<vec<ll>> adj;
vec<ll> vis, a;
vec<pll> dp;
// (win, lose)

void dfs(ll root) {
    vis[root] = true;
    ll win = 0, lose = 0;

    for (auto child : adj[root]) {
        if (!vis[child]) {
            dfs(child);
            win += dp[child].S;
            lose += dp[child].F;
        }
    }

    dp[root] = mp(max(win + a[root], lose), lose);
    return ;
}


ll _main() {
    ll n, ans = 0; cin >> n;
    adj.resize(n, vec<ll>());
    fill(all(adj), vec<ll>());
    vis.resize(n, false);
    fill(all(vis), false);
    dp.resize(n);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    for (int x, y, i = 0; i < n - 1; i++) {
        cin >> x >> y; 
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(0);

    return print(2 * ans - dp[0].F), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}