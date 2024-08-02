#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io             ios_base::sync_with_stdio(false);\
                                cin.tie(0); cout.tie(0)
#define print(n)            cout << (n) << endl
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

    vector<ll> cnt (5, 0);
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    ll ans = 0;
    if (cnt[3] > cnt[1]) {
        cnt[3] -= cnt[1];
        cnt[1] = 0;       // there is no 1;
        ans = cnt[3] - 1; // pick last one as 3;
    }
    else {
        cnt[1] -= cnt[3];
        cnt[3] = 0;      // there is no 3;
    }

    if (cnt[2] % 2 == 1) {
        if (cnt[1] > 1)
            cnt[1] -= 2; // balance 2's;
        else if (cnt[3])
            ans++;   // if we count 3 we must add padding
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