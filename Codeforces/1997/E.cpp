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
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


const ll mod = 1e9 + 7;
const ll inf = LONG_LONG_MAX;


ll _main() {
    ll n, q, i, x; 
    cin >> n >> q;

    vector<ll> monster (n), days (n, 0);
    for (i = 0; i < n; i++)
        cin >> monster[i];

    while (q--) {
        cin >> i >> x; 
        i--; x--;

        ll power = (days[x] / (x + 1)) + 1;
        if (monster[i] >= power) {
            // cout << "YES\n";
            cout << "YES" << endl;
            days[x]++;
        }
        else
            // cout << "NO\n";
            cout << "NO" << endl;

    }

    return print(""), 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}