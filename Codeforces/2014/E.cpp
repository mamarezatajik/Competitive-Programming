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


ll horse[maxN], n, m, h;
vector<pll> adj[maxN];


vector<pll> Dijkstra(ll src) {
    vector<pll> dist (n, {inf, inf});
    vector<pair<bool, bool>> vis (n, {false, false});
    priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>>> pq;
    if (horse[src]) {
        dist[src].F = 0;
        pq.push({{dist[src].F, src}, true});
    }
    else {
        dist[src].S = 0;
        pq.push({{dist[src].S, src}, false});
    }

    while (!pq.empty()) {
        auto [tmp, hrs] = pq.top();
        auto [d, u] = tmp;
        pq.pop();

        if ( hrs && vis[u].F) {
            continue;
        }
        if (!hrs && vis[u].S) {
            continue;
        }

        for (auto [v, w]: adj[u]) {
            if (hrs) {
                if (dist[v].F > d + w / 2) {
                    dist[v].F = d + w / 2;
                    pq.push({{  d + w / 2, v}, true});
                }
            }
            else {
                if (dist[v].S > d + w) {
                    dist[v].S = d + w;
                    pq.push({{  d + w, v}, horse[v]});
                }
            }
        }

        if (hrs) {
            vis[u].F = true;
        }
        else {
            vis[u].S = true;
        }
    }

    dist[src].F = dist[src].S = 0;
    return dist;
}


ll _main() {
    cin >> n >> m >> h;

    for (ll i = 0; i < n; i++) {
        adj[i].clear();
        horse[i] = false;
    }

    for (ll i = 0; i < h; i++) {
        ll u;
        cin >> u;
        u--;
        horse[u] = true;
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<pll> dist1 = Dijkstra(0);
    vector<pll> dist2 = Dijkstra(n - 1);

    ll ans = inf;
    if (dist1[n - 1].F == inf && dist1[n - 1].S == inf) {
        ans = -1;
    }
    else {
        for (ll i = 0; i < n; i++) {
            ans = min(ans, max(
                    min(dist1[i].F, dist1[i].S),
                    min(dist2[i].F, dist2[i].S)
                    ));
        }
    }

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}