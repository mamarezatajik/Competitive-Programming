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

const ll maxN = 4e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, ans;
ll a[maxN], b, ps[maxN];
vector<pll> adj[maxN];

vector<ll> dijkstra(ll src) {
    vector<ll> dist (n + 1, inf);
    vector<bool> vis (n + 1, false);
    dist[src] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[src], src});

    while(!pq.empty()) {
        ll u = pq.top().S;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        adj[i].clear();
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> b;
        adj[i].push_back({b, a[i]});
    }

    for (ll i = n; i >= 2; i--) {
        adj[i].push_back({i - 1, 0});
    }

    vector<ll> dist = dijkstra(1);

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (dist[i] == inf) {
            continue;
        }
        ans = max(ans, ps[i] - dist[i]);
    }

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}