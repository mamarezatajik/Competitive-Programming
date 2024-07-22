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
    ll n, m, j;
    cin >> n >> m;
    string s; cin >> s;
    vector<ll> ind (m), cnt (28, 0);
    for (int i = 0; i < m; i++) 
        cin >> ind[i];
    string c; cin >> c;
    for (int i = 0; i < m; i++) 
        cnt[c[i] - 'a']++;

    sort(all(ind));
    sort(all(c));

    for (ll i = 0; i < m; i++) {
        if (i < m - 1 && ind[i] == ind[i + 1]) {
            for (int j = 27; j >= 0; j--) {
                if (cnt[j]) {
                    s[ind[i] - 1] = j + 'a';
                    cnt[j]--; break; }
            }
        }
        else {
            for (int j = 0; j < 28; j++) {
                if (cnt[j]) {
                    s[ind[i] - 1] = j + 'a';
                    cnt[j]--; break;
                }
            }
        }
    }

    return print(s), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}