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
                                {print_vec(_);};
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
    ll n, m, mx = ll_min;
    ll l, r, u, d; 
    cin >> n >> m;

    vector<vector<ll>> a (n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    bool end = false;
    while (!end) {
        end = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                l = r = u = d = ll_min;
                if (j > 0)     l = a[i][j - 1];
                if (j < m - 1) r = a[i][j + 1];
                if (i > 0)     u = a[i - 1][j];
                if (i < n - 1) d = a[i + 1][j];

                if (a[i][j] > max({l, r, u, d}))
                    a[i][j] = max({l, r, u, d}), end = false;
            }
        }
    }

    print_vec_vec(a);

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