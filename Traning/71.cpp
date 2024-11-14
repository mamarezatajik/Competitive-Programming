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

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, trees, acorns, is_tree;
vector<char> adj[26];
bool alpha[26], vis[26];

void dfs(ll node, ll parent) {
    vis[node] = true;
    if (node == parent && len(adj[node]) == 0) {
        is_tree = false;
        acorns++;
        return;
    }

    for (ll child: adj[node]) {
        if (child == parent) {
            continue;
        }

        if (vis[child] == true) {
            is_tree = false;
        }
        dfs(child, node);
    }
}

ll _main() {
    string s;
    while (true) {
        cin >> s;
        if (s[0] == '*') {
            break;
        }

        adj[s[1] - 'A'].push_back(s[3] - 'A');
        adj[s[3] - 'A'].push_back(s[1] - 'A');
    }

    cin >> s;
    n = len(s);
    for (ll i = 0; i < n; i += 2) {
        alpha[s[i] - 'A'] = true;
    }

    trees = acorns = 0;
    for (ll i = 0; i < 26; i++) {
        if (alpha[i] && !vis[i]) {
            is_tree = true;
            dfs(i, i);
            if (is_tree) {
                trees++;
            }
        }
    }

    cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        for (ll i = 0; i < 26; i++) {
            adj[i].clear();
            alpha[i] = false;
            vis[i] = false;
        }
        _main();
    }
    return 0;
}