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
#define indexed_set         tree<pair<ld, ld>, null_type,less<pair<ld, ld>>,\
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

pair<ld, ld> pre(string s1, string s2) {
    char l, r; ld R, L;
    l = s1[0], r = s2[len(s2) - 1];
    s1 = s1.substr(1, len(s1) - 2);
    s2 = s2.substr(0, len(s2) - 1);

    L = (s1 == "-inf") ? ll_min : ((ld) stoi(s1));
    R = (s2 ==  "inf") ? ll_max : ((ld) stoi(s2));

    if (l == '(' && L != ll_min)
        L += 0.5;
    if (r == ')' && R != ll_max)
        R -= 0.5;

    return mp(L, R);
}

ll _main() {
    ll n; cin >> n; 
    string s1, s2; 
    ld L, R;
    indexed_set idset; 
    idset.clear();

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        pair<ld, ld> it_curr = pre(s1, s2);
        ll order = idset.order_of_key(it_curr);
        ll size = len(idset);

        if (size < 1) {
            idset.insert(it_curr);
            continue;
        }

        auto it_next = idset.find_by_order(order);
        auto it_prev = idset.find_by_order(order - 1);
        if (order == 0) { // move right
            ll cnt = 0;   // place back
            while (cnt < size && 
                (*it_next).F <= it_curr.S || ((*it_next).F - it_curr.S == 0.5)) {
                    cnt++;
                    it_next = idset.find_by_order(order + cnt);
            }

            if (cnt == 0)
                idset.insert(it_curr);
            while (cnt--)
                idset.erase(idset.find_by_order(order));
            idset.insert(mp(it_curr.F, max(it_curr.S, (*it_next).S)));
        }

        else if (order == size) { // one check back
            ld diff = it_curr.F - (*it_prev).S;
            if ((*it_prev).S >= it_curr.F || (0 < diff && diff < 1)) {
                pair<ld, ld> tmp = *it_prev;
                idset.erase(it_prev); // place front
                idset.insert(mp(tmp.F, max(it_curr.S, tmp.S)));
            }
            else
                idset.insert(it_curr);
        }

        else { // place middle
            if ((*it_prev).S >= it_curr.F || (it_curr.F - (*it_prev).S == 0.5)) {
                pair<ld, ld> tmp = *it_prev;
                idset.erase(it_prev); // place front
                idset.insert(mp(tmp.F, max(it_curr.S, tmp.S)));
            }

            ll cnt = 0;   // move right
            while (cnt < size && 
                (*it_next).F <= it_curr.S || ((*it_next).F - it_curr.S == 0.5)) {
                    cnt++;
                    it_next = idset.find_by_order(order + cnt);
            }

            if (cnt == 0)
                idset.insert(it_curr);
            while (cnt--)
                idset.erase(idset.find_by_order(order));
            idset.insert(mp(it_curr.F, max(it_curr.S, (*it_next).S)));
        }
    }

    ll ctr = 0;
    for (auto &[a, b] : idset) {
        if (a == ll_min)
            cout << "(-inf";
        else {
            cout << (((ll) a == a) ? '[' : '(');
            cout << (((ll) a == a) ? a : (a - 0.5));
        }
        cout << ", ";

        if (b == ll_max)
            cout << "inf)";
        else {
            cout << (((ll) b == b) ? b : (b + 0.5));
            cout << (((ll) b == b) ? ']' : ')');
        }
        cout << ' ';

        if (++ctr < len(idset))
            cout << "U ";   
    }
    cout << '\n';

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