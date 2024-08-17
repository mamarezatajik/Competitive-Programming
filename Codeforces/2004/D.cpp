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


string cities[maxN];
map<string, vector<ll>> cityIndices;

bool haveCommonChar(ll x, ll y) {
    bool ok = false;

    if (cities[x][0] == cities[y][0] ||
        cities[x][0] == cities[y][1] ||
        cities[x][1] == cities[y][0] ||
        cities[x][1] == cities[y][1])
            ok = true;

    if (ok) {
        cout << y - x << '\n';
        return true; }

    return false;
}

ll _main() {
    ll n, q; cin >> n >> q;
    cityIndices.clear();

    for (ll i = 0; i < n; i++) {
        cin >> cities[i];
        cityIndices[cities[i]].push_back(i);
    }

    vector<string> allCities;
    for (auto [city, indices]: cityIndices)
        allCities.push_back(city);

    for (ll i = 0; i < q; i++) {
        ll x, y; cin >> x >> y;
        if (x > y)
            swap(x, y);
        x--, y--;

        if (haveCommonChar(x, y))
            continue;

        ll minDistance = inf;
        bool isBetween = false;
        for (string city : allCities) {
            if (city == cities[x] || city == cities[y])
                continue;

            auto cityIndex = lower_bound(all(cityIndices[city]), x);
            if (cityIndex != cityIndices[city].end()) {
                minDistance = min(minDistance, *cityIndex - y);
                if (*cityIndex <= y)
                    isBetween = true;
            }
            if (cityIndex != cityIndices[city].begin())
                minDistance = min(minDistance, x - *(cityIndex - 1));
        }

        if (minDistance == inf)
            cout << -1;
        else if (isBetween)
            cout << y - x;
        else
            cout << (y - x) + (2 * minDistance);
        cout << '\n';
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