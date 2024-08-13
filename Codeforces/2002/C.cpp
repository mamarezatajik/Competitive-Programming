#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

ll distance (ll x1, ll x2, ll y1, ll y2) {
    ll diffX = abs(x1 - x2);
    ll diffY = abs(y1 - y2);
    return (diffX * diffX + diffY * diffY);
}

ll _main() {
    ll n, xStart, yStart, xEnd, yEnd; 
    cin >> n;

    vector<pll> a (n);
    for (ll i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;

    cin >> xStart >> yStart >> xEnd >> yEnd;
    ll pointDist = distance(xStart, xEnd, yStart, yEnd);

    ll minDist = inf;
    for (ll i = 0; i < n; i++) {
        ll res = distance(a[i].F, xEnd, a[i].S, yEnd);
        minDist = min(res, minDist);
    }

    bool win = true;
    if (minDist <= pointDist)
        win = false;

    return cout << (win ? "YES" : "NO") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}