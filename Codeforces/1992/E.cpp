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
string s;
ll _s, n, a = 1, b;

bool ok(ll ans) {
    ll cnt = n * a - b;
    ll j = 0, res = 0;
    for (int i = cnt; i > 0; i--)
        res += (s[j++ % n] - '0') * (ll) pow(10, i - 1);
    return ans == res;
}


ll _main() {
    s.clear(); cin >> s;
    _s = stoi(s); n = len(s);

    ll ans = _s, z = 0;
    vec<pll> anss ;
    while (ans < 1e6) {
        a = min(1ll, ((1 + ans) / _s) - 1);
        while (a <= 10000) {
            b = _s * a - ans;
            if (ok(ans))
                anss.pb(mp(a, b));
            a++;
        }
        if (n == 1)
            ans = ans * (ll) pow(10, n) + _s;
        else
            ans = ans * 10 + (s[z++ % n] - '0');
    }

    print(len(anss));
    for (int i = 0; i < len(anss); i++)
        cout << anss[i].F << ' ' << anss[i].S << '\n';
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