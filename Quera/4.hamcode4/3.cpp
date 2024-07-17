#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io             ios_base::sync_with_stdio(false);\
                                cin.tie(0); cout.tie(0)
#define print(n)            cout << (n) << endl
#define print_vec(arr)      for (auto __ : arr)\
                                cout << __; cout << endl
#define print_vec_vec(arr)  for (auto _ : arr)\
                                {print_vec(_);};
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


ll a, b;
vec<vec<ll>> row, col;
vec<vec<char>> grid;
vec<vec<vec<ll>>> block;

bool is_valid(ll i, ll j, ll x) {
    if (row[i][x])
        return false;
    if (col[j][x])
        return false;
    if (block[i / a][j / b][x])
        return false;
    if (grid[i][j] != '.')
        return false;

    row[i][x] = col[j][x] = block[i / a][j / b][x] = true;
    grid[i][j] = (x + 1) + '0';
    print_vec_vec(grid);

    return true;
}


ll _main() {
    ll n, i, j, x; 
    cin >> a >> b >> n;
    grid.resize(a * b, vec<char> (a * b, '.'));
    row.resize(a * b, vec<ll> (a * b, false));
    col.resize(a * b, vec<ll> (a * b, false));
    block.resize(b , vec<vec<ll>> (a, vec<ll> (a * b, false)));

    bool player1 = true;

    for (int ctr = 0; ctr < n; ctr++) {
        cin >> i >> j >> x;
        i--;   j--;   x--;

        if (player1)
            print("player 1:");
        else
            print("player 2:");

        if (!is_valid(i, j, x))
            print("invalid move");
        else
            player1 = !player1;
    }

    return 0;
}


signed main() {
    fast_io;

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}