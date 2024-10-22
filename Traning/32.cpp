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

const ll maxN = 5e2 + 10;
const ll inf  = 7e16 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


vector<pll> adj[maxN];
string s, t;
ll n, dist[26][26];

void Dijkstra(char alpha) {
    ll src = alpha - 'a';

    for (ll i = 0; i < 26; i++) {
        dist[src][i] = inf;
    }
    dist[src][src] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[src][src], src});

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto [v, w]: adj[u]) {
            if (dist[src][v] > dist[src][u] + w) {
                dist[src][v] = dist[src][u] + w;
                pq.push({ dist[src][v], v});
            }
        }
    }
}


ll _main() {
    cin >> s;
    cin >> t;

    cin >> n;
    for (ll i = 0; i < n; i++) {
        char a, b;
        ll w;
        cin >> a >> b >> w;
        ll u = a - 'a';
        ll v = b - 'a';
        adj[u].push_back({v, w});
    }

    if (len(s) != len(t)) {
        return cout << -1, 0;
    }

    for (char i = 'a'; i <= 'z'; i++) {
        Dijkstra(i);
    }

    ll ans = 0, better, best;
    string res;
    for (ll i = 0; i < len(s); i++) {
        best = 0;
        better = min(dist[s[i] - 'a'][t[i] - 'a'],
                    dist[t[i] - 'a'][s[i] - 'a']);

        for (ll j = 0; j < 26; j++) {
            ll dst = dist[s[i] - 'a'][j] + dist[t[i] - 'a'][j];
            if (dst < dist[s[i] - 'a'][best] + dist[t[i] - 'a'][best]) {
                best = j;
            }
        }

        ll good = dist[s[i] - 'a'][best] + dist[t[i] - 'a'][best];

        if (good == better && better == inf) {
            return cout << -1, 0;
        }

        ans += min(good, better);
        if (better > good) {
            res += (best + 'a');
        }
        else if (better == dist[s[i] - 'a'][t[i] - 'a']) {
            res += t[i];
        }
        else {
            res += s[i];
        }
    }

    cout << ans << '\n';
    return cout << res, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}