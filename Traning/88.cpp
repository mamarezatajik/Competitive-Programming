#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 22;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, t, v, ctr = 1;
vector<pair<ll, vector<ll>>> a[maxN];

ll _main() {
    while (cin >> n >> k && n != 0 && k != 0) {
        for (int i = 0; i < maxN; i++) {
            a[i].clear();
        }
        vector<ll> b(n);
        t = 1;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        } 
        a[t].push_back({v, b});

        cin >> m;
        while (m--) {
            cin >> t;
            vector<ll> tmp(t);
            for (int i = 0; i < t; i++) {
                cin >> tmp[i];
            }
            cin >> v;
            a[t].push_back({v, tmp});
        }

        vector<ll> locations (k);
        ll maxPopulation = -inf;
        for (int mask = 0; mask < (1 << n); mask++) {
            ll cnt = 0;
            ll population = 0;
            set<ll> idx;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    idx.insert(i + 1);
                    population += a[1][0].S[i];
                }
            }
            if (cnt != k) {
                continue;
            }

            for (int i = 2; i <= 21; i++) {
                for (auto [val, vec] : a[i]) {
                    ll cnt = 0;
                    for (ll vv: vec) {
                        if (idx.count(vv)) {
                            cnt++;
                        }
                    }
                    if (cnt > 1) {
                        population -= (val * (cnt - 1));
                    }
                }
            }


            if (maxPopulation < population) {
                maxPopulation = population;
                locations = vector<ll>(all(idx));
            } 
            else if (maxPopulation == population) {
                vector<ll> tmp(all(idx));
                if (locations > tmp) {
                    locations = tmp;
                }
            }
        }

        cout << "Case Number  " << ctr++ << "\n";  
        cout << "Number of Customers: " << maxPopulation << "\n";  
        cout << "Locations recommended:";  
        for (int loc : locations) {  
            cout << ' ' << loc;  
        }  
        cout << "\n\n";
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}