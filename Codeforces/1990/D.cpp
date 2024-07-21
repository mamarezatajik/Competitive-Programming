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
    ll n, x; cin >> n;
    ll ans = 0;

    vector<vector<bool>> a (n, vector<bool>(4, 0));
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 4) {
            ans++;
            continue;
        }
        for (int j = 0; j < x; j++) 
            a[i][j] = 1;
    }

    bool blockL = false, blockR = false;
    for (int i = 0; i < n; i++) {
        if (a[i][0]) {
            if (blockL) {
                if (a[i][2])
                    blockR = true, ans++;
                blockL = false;
            }
            else if (blockR) {
                if (a[i][0])
                    blockL = true, ans++;
                blockR = false;
            }
            else {
                if (!a[i][2])
                    blockL = true;
                ans++;
            }
        }
        else
            blockL = blockR = false;
    }

    return print(ans), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}