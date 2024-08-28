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


vector<ll> adj[maxN];

pll findMex(vector<ll>& a, ll n) {
    sort(all(a));

    ll minMex = 0;
    for (ll i = 0; i < n; i++) {
        minMex += minMex == a[i];
    }

    a.push_back(minMex);
    sort(all(a));
    n++;

    ll maxMex = 0;
    for (ll i = 0; i < n; i++) {
        maxMex += maxMex == a[i];
    }

    return {minMex, maxMex};
}


ll _main() {
    ll n, m, l; 
    cin >> n >> m;

    ll bestMaxMex = 0, bestMinMex = 0;
    for (ll i = 0; i < n; i++) {
        cin >> l;
        vector<ll> a (l);
        for (ll j = 0; j < l; j++) {
            cin >> a[j];
        }
        auto [minMex, maxMex] = findMex(a, l);

        adj[minMex].push_back(maxMex);
        bestMaxMex = max(maxMex, bestMaxMex);
        bestMinMex = max(minMex, bestMinMex);
    }

    vector<ll> dp (bestMaxMex + 1);
    ll maxDuplicate = 0;
    for (ll i = bestMaxMex; 0 <= i; i--) {
        dp[i] = i;
        for (ll maxMex : adj[i]) {
            dp[i] = max(dp[i], dp[maxMex]);
        }
        if (len(adj[i]) > 1) {
            maxDuplicate = max(maxDuplicate, dp[i]);
        }
        adj[i].clear();
    }

    ll ans = m * (m + 1) / 2;
    for (ll i = 0; i <= min(bestMaxMex, m); i++) {
        ans += max({bestMinMex, maxDuplicate, dp[i]}) - i;
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