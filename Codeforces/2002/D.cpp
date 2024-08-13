#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 7e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, perm[maxN], maxDepth;


bool query(ll node, ll depth, ll value) {
    ll lft = 2 * node + 1;
    ll rgt = 2 * node + 2;

    if (depth == maxDepth) {
        if (node % 2 == 0) {
            if (perm[node] == value &&
                perm[node - 1] == value + 1)
                    return true;
            if (perm[node] == value + 1 &&
                perm[node - 1] == value)
                    return true;
        }
        else {
            if (perm[node] == value &&
                perm[node + 1] == value + 1)
                    return true;
            if (perm[node] == value + 1 &&
                perm[node + 1] == value)
                    return true;
        }
        return false;
    }

    ll numSubtrees = (1 << (maxDepth - depth));
    if (perm[lft] == value + 1) {
        if (perm[rgt] != numSubtrees + value)
            return false;
        else
            return query(lft, depth + 1, value + 1) || 
                query(rgt, depth + 1, numSubtrees + value);
    }
    else if (perm[rgt] == value + 1) {
        if (perm[lft] != numSubtrees + value)
            return false;
        else
            return query(rgt, depth + 1, value + 1) || 
                query(lft, depth + 1, numSubtrees + value);
    }
    else
        return false;
}

ll _main() {
    ll q, x, y; 
    cin >> n >> q;
    maxDepth = log2(n) + 1;

    for (ll a, i = 1; i < n; i++) 
        cin >> a;

    for (ll i = 0; i < n; i++)
        cin >> perm[i];


    while (q--) {
        cin >> x >> y;
        x--, y--;
        swap(perm[x], perm[y]);
        cout << (query(0, 1, 1) ? "YES" : "NO") << '\n';
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