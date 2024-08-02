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
    ll n, k; cin >> n >> k;

    vector<ll> prefixSum (n + 1, 0), awakeSum (n + 1, 0);
    ll best = 0, diffPrefix, diffAwake, notSleep, a;
    for (int j, i = 1; i <= (2 * n); i++) {
        if (i <= n) {
            ll tmp; cin >> tmp;
            prefixSum[i] = prefixSum[i - 1] + tmp;
            continue;
        }

        j = (i % (n + 1)) + 1;
        cin >> notSleep;
        a = prefixSum[j] - prefixSum[j - 1];
        awakeSum[j] = awakeSum[j - 1];

        if (notSleep)
            awakeSum[j] += a;

        if (j >= k) {
            diffAwake = awakeSum[j] - awakeSum[j - k];
            diffPrefix = prefixSum[j] - prefixSum[j - k];
            best = max(best, diffPrefix - diffAwake);
        }
    }

    return print(awakeSum[n] + best), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}