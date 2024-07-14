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


ll _main() {
    ll n, m, k, pre = 0; 
    cin >> n >> m >> k;
    string a; cin >> a;
    a = 'L' + a + 'L';

    vec<pair<bool, ll>> dp (n + 2);
    dp[0].F = true, dp[0].S = k;


    for (int i = 1; i < n + 2; i++) {
        if (a[i] == 'C')
            dp[i] = mp(false, -1);

        else if (a[i] == 'L') {
            if (i - pre <= m) {
                dp[i] = dp[pre];
            }
            else {
                if (dp[i - 1].F)
                    dp[i] = mp(true, dp[i - 1].S - 1);
                else
                    dp[i] = mp(false, -1);
            }
            pre = i;
        }

        else {   // a[i] == 'W'
            if (i - pre <= m)
                dp[i] = dp[pre];
            else if (dp[i - 1].F)
                dp[i] = mp(true, dp[i - 1].S - 1);
            else
                dp[i] = mp(false, -1);
        }
    }


    if (dp[n + 1].F && dp[n + 1].S >= 0)
        return print("YES"), 0;
    return print("NO"), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}