#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

string a[maxN];
unordered_map<string, vector<ll>> m;

ll _main() {
    ll n, q; cin >> n >> q;

    m.clear();
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }


    while (q--) {
        ll x, y; cin >> x >> y;
        x--, y--;
        if (y < x)
            swap(x, y);
        if (a[x][0] == a[y][0] ||
            a[x][0] == a[y][1] ||
            a[x][1] == a[y][0] ||
            a[x][1] == a[y][1]) {
                cout << abs(y - x) << '\n';
                continue;
            }

        vector<string> cities (4);
        for (ll i = 0; i < 2; i++) 
            for (ll j = 0; j < 2; j++) {
                cities[i * 2 + j] += a[x][i];
                cities[i * 2 + j] += a[y][j];
                sort(cities[i * 2 + j].begin(), cities[i * 2 + j].end());
            }

        bool foundMid = false;
        for (auto city : cities) {
            vector<ll> v = m[city];
            if (!len(v))
                continue;
            ll idx = lower_bound(all(v), x) - v.begin();
            if (0 <= idx && idx < len(v) && x < v[idx] && v[idx] < y)
                foundMid = true;
        }
        if (foundMid) {
            cout << abs(y - x) << '\n';
            continue;
        }

        ll best = inf;
        for (auto city : cities) {    
            vector<ll> v = m[city];
            if (!len(v))
                continue;
            ll idx = lower_bound(all(v), y) - v.begin();
            if (0 <= idx && idx < len(v) && v[idx] > y)
                best = min(best, v[idx] - y);
        }

        for (auto city : cities) {
            vector<ll> v = m[city];
            if (!len(v))
                continue;
            ll idx = lower_bound(all(v), x) - v.begin();
            if (0 <= idx && idx < len(v) && x > v[idx])
                best = min(best, x - v[idx]);
            idx--;
            if (0 <= idx && idx < len(v) && x > v[idx])
                best = min(best, x - v[idx]);
        }

        cout << (best == inf ? -1 : ((abs(y - x)) + (2 * best))) << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}