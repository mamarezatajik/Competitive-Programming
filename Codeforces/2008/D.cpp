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


ll perm[maxN];


ll _main() {
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
        cin >> perm[i];
    }

    string s;
    cin >> s;
    s = ' ' + s;

    vector<pair<ll, vector<ll>>> cmp;
    vector<ll> vis (n + 1, false);
    map<ll, ll> rev;
    ll ctr = 0;

    for (ll i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        ll j = i;
        ll cnt = 0;
        vector<ll> tmp;
        while (!vis[j]) {
            rev[j] = ctr;
            tmp.push_back(j);
            if (s[j] == '0') {
                cnt++;
            }
            vis[j] = true;
            j = perm[j];
        }
        ctr++;
        cmp.push_back({cnt, tmp});
    }

    for (ll i = 1; i <= n; i++) {
        cout << cmp[rev[i]].F << ' ';
    }

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