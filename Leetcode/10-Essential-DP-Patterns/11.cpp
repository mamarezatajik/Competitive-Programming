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


int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    if (n == 1)
        return matrix[0][0];

    vector<vector<int>> dp (n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        dp[0][i] = matrix[0][i];

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = matrix[i][j];
            if (j == 0)
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j + 1]);
            else if (j == n - 1)
                dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
            else
                dp[i][j] += min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
            if (i == n - 1)
                ans = min(ans, dp[i][j]);
        }
    }

    return ans;
}

ll _main() {
    ll n, m; cin >> n >> m;

    vec<vec<int>> a (n, vec<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    return print(minFallingPathSum(a)), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}