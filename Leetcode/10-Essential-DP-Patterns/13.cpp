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


    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        int I = 0, J = 0;

        for (int i = 0; i < n; i++) 
            dp[0][i] = 1;

        for (int j = 1; j < n; j++)
            for (int i = 1; i < j + 1; i++)
                if (s[j - i] == s[j] && (
                    (i == 1 || dp[i - 2][j - 1]))) {
                        dp[i][j] = true;
                        if ((J - I) < i)
                            J = j, I = j - i;
                }
        return string(s, I, J - I + 1);
    }

ll _main() {
    string s; cin >> s;
    return print(longestPalindrome(s)), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}