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
    ll n, q, l, r; cin >> n >> q;
    string a, b; cin >> a >> b;

    vector<vector<ll>> dp1 (n + 1, vector<ll>(28, 0));
    vector<vector<ll>> dp2 (n + 1, vector<ll>(28, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 28; j++) {
            if (j == a[i] - 'a')
                dp1[i + 1][j] = dp1[i][j] + 1;
            else
                dp1[i + 1][j] = dp1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 28; j++) {
            if (j == b[i] - 'a')
                dp2[i + 1][j] = dp2[i][j] + 1;
            else
                dp2[i + 1][j] = dp2[i][j];
        }
    }

    while (q--) {
        cin >> l >> r;

        ll cnt1 = 0, cnt2 = 0, ans = 0;
        for (int i = 0; i < 28; i++) {
            cnt1 = (dp1[r][i] - dp1[l - 1][i]);
            cnt2 = (dp2[r][i] - dp2[l - 1][i]);
            ans += abs(cnt1 - cnt2);
        }

        print(ans / 2);
    }

    return 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}