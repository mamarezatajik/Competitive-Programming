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
    ll n; cin >> n;

    string top, bot;
    cin >> top >> bot;

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (top[i] == 'x')
            continue;
        if (top[i - 1] == top[i] && 
            top[i] == top[i + 1] &&
            bot[i] == top[i] &&
            bot[i - 1] == bot[i + 1] &&
            bot[i + 1] == 'x')
                ans++;
    }

    for (int i = 1; i < n - 1; i++) {
        if (bot[i] == 'x')
            continue;
        if (bot[i - 1] == bot[i] && 
            bot[i] == bot[i + 1] &&
            top[i] == bot[i] &&
            top[i - 1] == top[i + 1] &&
            top[i + 1] == 'x')
                ans++;
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