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
template<class T>
#define indexed_set         tree<T, null_type,less<T>,\
                                rb_tree_tag,\
                                tree_order_statistics_node_update>
#define ll_max              LONG_LONG_MAX
#define ll_min              LONG_LONG_MIN
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


ll mod = 1e9 + 7;


ll _main() {
    ll n, x, h; 
    cin >> n;
    vector<pll> a (n);
    vector<ll> dp (n);

    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        a[i] = {x, h};
    }

    dp[0] = a[0].F;

    if (n <= 2)
        return print(n), 0;

    ll ans = 2, pre; 
    pll  nxt, cur;
    for (int i = 1; i < n - 1; i++) {
        pre = dp[i - 1];
        cur = a[i];
        nxt = a[i + 1];

        if (pre < cur.F - cur.S)
            dp[i] = cur.F, ans++;
        else if (cur.F + cur.S < nxt.F)
            dp[i] = cur.F + cur.S, ans++;
        else
            dp[i] = cur.F;
    }

    return print(ans), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}