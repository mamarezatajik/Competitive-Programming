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


ll _main() {
    ll n; cin >> n;
    vector<ll> a (n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll m; cin >> m;
    for (ll i = 0; i < m; i++) {
        string s; cin >> s;
        if (len(s) != n) {
            cout << "NO\n";
            continue;
        }

        map<char, ll> m1;
        map<ll, char> m2;
        for (char i = 'a'; i <= 'z'; i++)
            m1[i] = inf;

        for (ll i = 0; i < n; i++) 
            m2[a[i]] = '*';

        bool ok = true;
        for (ll i = 0; i < n; i++) {
            if (m1[s[i]] == inf && m2[a[i]] == '*')
                m1[s[i]] = a[i], m2[a[i]] = s[i];
            else if (m1[s[i]] != a[i] || m2[a[i]] != s[i])
                ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
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