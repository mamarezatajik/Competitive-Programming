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


    bool wordBreak(string s, vector<string>& wordDict) {
        int len, n = wordDict.size();
        set<string> dict;
        for (int i = 0; i < n; i++) 
            dict.insert(wordDict[i]);
        n = s.size();

        vector<vector<bool>> dp (n, vector<bool>(n));

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j + 1; i++) {
                string sub = s.substr(j - i, i + 1);
                if (dict.count(sub))
                    dp[i][j] = 1;

                if (dp[i][j]) {
                    len = j - i - 1;
                    for (int k = 0; k < len + 1; k++) {
                        if (dp[k][len])
                            dp[i + k + 1][j] = 1;
                    }
                }
            }
        }

        return dp[n - 1][n - 1];
    }

ll _main() {
    string s; cin >> s;
    ll n; cin >> n;
    vector<string> v (n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    return print(wordBreak(s, v)), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}