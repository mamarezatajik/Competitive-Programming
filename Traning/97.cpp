#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<int, int>      pii;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const int inf  = 2e9 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;




ll _main() {
    // while (true) {
    int i, j, n;
    n = rng() % 10000 + 1;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> st(3);
    for (i = 0; i < n; i++) {
        cin >> a[i];
        // a[i] = rng() % 3;
        st[a[i]].insert(i);
    }

    bool haveOne = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            haveOne = true;
        }
    }
    if (!haveOne) {
        st[a[n - 1]].erase(n - 1);
        a[n - 1] = 1;
        st[1].insert(n - 1);
    }


    int firstOne, lastOne, firstTwo = inf, lastZero = -inf;
    vector<pii> moves;
    // cout << 1 << endl;
    // cout << n << '\n';
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << ' ';
    // } cout << endl;
    for (i = 0; i < n; i++) {
        if (!st[0].empty()) {
            lastZero = *(prev(st[0].end()));
        }
        firstOne = *st[1].begin();

        if (firstOne < lastZero) {
            moves.push_back({firstOne, lastZero});
            st[1].erase(firstOne); st[1].insert(lastZero);
            st[0].erase(lastZero); st[0].insert(firstOne);
            swap(a[firstOne], a[lastZero]);
        }

        if (!st[2].empty()) {
            firstTwo = *st[2].begin();
        }
        lastOne = *(prev(st[1].end()));

        if (firstTwo < lastOne) {
            moves.push_back({firstTwo, lastOne});
            st[2].erase(firstTwo); st[2].insert(lastOne);
            st[1].erase(lastOne); st[1].insert(firstTwo);
            swap(a[firstTwo], a[lastOne]);
        }
    }

    // for (i = 0; i < n; i++) {
    //     cout << a[i] << " \n"[i == n - 1];
    // }

    // if (len(moves) > n) {
    //     cout << "-----\n";
    //     cout << n << 'n';
    //     for (int i = 0; i < n; i++) {
    //         cout << a[i] << ' ';
    //     }
    //     break;
    // }

    cout << len(moves) << '\n';
    for (auto [l, r]: moves) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    // }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}