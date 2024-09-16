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

ll add(ll a, ll b) {
    a *= pow(10, len(to_string(b)));
    a += b;
}

ll n, m, dist[maxN];
vector<pll> adj[maxN];


void Dijkstra(ll src) {
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[src], src});

    

}


ll _main() {
    cin >> n >> m;
    ll w = 1;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        w++;
    }

    Dijkstra(0);


    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}