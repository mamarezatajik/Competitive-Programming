#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io             ios_base::sync_with_stdio(false);\
                                cin.tie(0); cout.tie(0)
#define print(n)            cout << (n) << '\n'
#define print_vec(arr)      for (auto __ : arr)\
                                cout << __ << ' '; cout << '\n'
#define print_vec_vec(arr)  for (auto _ : arr)\
                                {print_vec(_);}; cout << '\n'
#define all(arr)            arr.begin(), arr.end()
#define rall(arr)           arr.rbegin(), arr.rend()
#define len(arr)            (ll) (arr.size())
template<class T>
#define indexed_set         tree<T, null_type,less<T>,\
                                rb_tree_tag,\
                                tree_order_statistics_node_update>
#define ll_max              LONG_LONG_MAX
#define ll_min              LONG_LONG_MIN
#define pll                 pair<ll, ll>
#define ll                  long long
#define ld                  long double
#define mp                  make_pair
#define pb                  push_back
#define F                   first
#define S                   second


ll mod = 1e9 + 7;

vector<vector<ll>> adj;
vector<ll> color, p1, p2;
ll n, m, isBipartite;


void Bob() {
    cout << "Bob" << endl;
    ll a, b, i, c;

    for (int j = 0; j < n; j++) {
        cin >> a >> b;

        if ((a == 1) || (b == 1)) { // assign 1 to p1;
            if (len(p1)) { 
                i = p1.back();
                c = 1; p1.pop_back();
            }
            else { // assign 2 or 3 to p2;
                i = p2.back(); p2.pop_back();
                c = ((a != 1) ? a : b);
            }
        } 
        else { // there is a 2 and assign to p2;
            if (len(p2)) {
                i = p2.back();
                c = 2; p2.pop_back();
            }
            else { // assign 2 or 3 to p1;
                i = p1.back(); p1.pop_back();
                c = ((a != 2) ? a : b);
            }
        }

        cout << i << ' ' << c << endl;
    }
}

void Alice() {
    int i, c;
    cout << "Alice" << endl;
    for (int j = 0; j < n; j++) {
        cout << "1 2" << endl;
        cin >> i >> c;
    }
}

void is_bipartite(ll u, ll c) {
    if (color[u] != -1 &&
        color[u] != c)
            isBipartite = false;
    if (c) p1.pb(u + 1);
    else   p2.pb(u + 1);
    color[u] = c;

    for (ll v : adj[u]) {
        if (color[v] == -1)
            is_bipartite(v, 1 - c);
        if (color[v] != -1 && color[v] != 1 - c)
            isBipartite = false;
    }
}

ll _main() {
    ll u, v;  cin >> n >> m; 
    adj.clear(); adj.resize(n, vector<ll>()); 
    fill(all(adj), vector<ll>());
    color.clear(); color.resize(n);
    fill(all(color), -1);
    p1.clear(); p2.clear();

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--,    v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    isBipartite = true;
    is_bipartite(0, 0);

    if (!isBipartite)
        Alice();
    else
        Bob();

    return 0;
}

signed main() {
    fast_io;

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}