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


ll _main() {
    ll n; cin >> n;
    string s;
    map<string, int> m;

    m["white"] = 0, m["red"] = 1;
    m["yellow"] = 2, m["green"] = 3;
    m["brown"] = 4, m["blue"] = 5;
    m["pink"] = 6, m["black"] = 7;

    int first = 0, second = 0;
    bool put = false, turn = true;
    int red_cnt = 0;

    while (n--) {
        cin >> s;

        if (s == "red") {
            red_cnt++;
            if (turn)
                first += m[s];
            else
                second += m[s];
            put = true;
        }
        else if (s == "white" || s == "miss")
            turn = !turn, put = false;
        else {
            if (m[s] == -1)
                return print("Invalid"), 0;
            if (put) {
                if (turn)
                    first += m[s];
                else
                    second += m[s];
                if (red_cnt == 15)
                    m[s] = -1;
            } 
            else
                turn = !turn;
            put = false;
        }
    }


    if (red_cnt > 15)
        print("Invalid");
    else if (first > second)
        print("First");
    else if (first == second)
        print("Tie");
    else
        print("Second");

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