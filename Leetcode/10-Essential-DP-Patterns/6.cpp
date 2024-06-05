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


int deleteAndEarn(vector<int>& nums) {
    vector<int> arr; arr.clear();
    unordered_map<int, int> cnt; cnt.clear();

    for (auto num : nums) {
        if (!cnt.count(num))
            arr.push_back(num);
        cnt[num]++;
    }
    sort(arr.begin(), arr.end());

    int n = arr.size();
    vector<int> dp (n);
    dp[0] = arr[0] * cnt[arr[0]];

    for (int i = 1; i < n; i++) {
        dp[i] = arr[i] * cnt[arr[i]];
        if (arr[i] - 1 == arr[i - 1]) {
            if (i >= 2)
                dp[i] += dp[i - 2];
        }
        else
            dp[i] += dp[i - 1];
        dp[i] = max(dp[i], dp[i - 1]);
    }

    return dp[n - 1];
}

ll _main() {
    ll n; cin >> n;

    vec<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    return print(deleteAndEarn(a)) , 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}