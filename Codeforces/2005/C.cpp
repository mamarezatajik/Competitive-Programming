#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll k, dp[maxN], par[maxN];
string a = "narek";


ll _main() {
    ll n, m;
    cin >> n >> m;
    string s;
    k = 0;

    map<char, ll> prePos;
    vector<vector<ll>> intervals;

    for (ll i = 0; i < n; i++) {
        string t;
        cin >> t;
        s += t;
    }

    for (ll i = 0; i < n * m; i++) {
        prePos[s[i]] = i;
        if (s[i] == a[k]) {
            k++;
            if (s[i] == 'n') {
                dp[i] = 1;
                par[i] = i;
            }
            else {
                ll idx = prePos[a[k - 1]];
                dp[i] = dp[idx] + 1;
                par[i] = idx;
            }
        }
        if (k == 5) {
            k = 0;
            vector<ll> tmp;
            tmp.push_back(i);
            ll r = i, l = i;
            while (par[l] != l) {
                tmp.push_back(par[l]);
                l = par[l];
            }
            reverse(all(tmp));
            intervals.push_back(tmp);
        }
    }

    vector<ll> b(n, 0);
    for (auto interval: intervals) {
        for (auto idx: interval) {
            b[idx / m]++;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        
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