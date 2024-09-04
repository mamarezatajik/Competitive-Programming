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


ll a[maxN];


ll _main() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    map<char, ll> m1, m2;
    char mx1 = 0, mx2 = 0;
    for (ll i = 0; i < n; i += 2) {
        m1[s[i]]++;
        if (m1[s[i]] > m1[mx1]) {
            mx1 = s[i];
        }
    }
    for (ll i = 1; i < n; i += 2) {
        m2[s[i]]++;
        if (m2[s[i]] > m2[mx1]) {
            mx2 = s[i];
        }
    }

    if (n % 2 == 0) {
        return cout << (n - m1[mx1] - m2[mx2]) << '\n', 0;
    }

    ll ans = inf;
    bool turn = false;
    ll mx11 = 0, mx22 = 0;
    m1[s[0]]--;
    for (ll i = 1; i < n - 1; i++) {
        if (turn) {
            m1[s[i]]--;
            m1[s[i - 1]]++;
        }
        else {
            m2[s[i]]--;
            m2[s[i - 1]]++;
        }
        turn = !turn;

        mx11 = mx22 = 0;
        for (auto [c, cnt] : m1) {
            mx11 = max(cnt, mx11);
        }
        for (auto [c, cnt] : m2) {
            mx22 = max(mx22, cnt);
        }
        ans = min(ans, n - mx11 - mx22);
    }

    m1.clear(); 
    m2.clear();
    mx1 = 0, mx2 = 0;
    m1[s[0]]--;
    for (ll i = 0; i < n; i += 2) {
        m1[s[i]]++;
        if (m1[s[i]] > m1[mx1]) {
            mx1 = s[i];
        }
    }
    for (ll i = 1; i < n; i += 2) {
        m2[s[i]]++;
        if (m2[s[i]] > m2[mx1]) {
            mx2 = s[i];
        }
    }
    ans = min(ans, n - m1[mx1] - m2[mx2]);

    m1.clear(); 
    m2.clear();
    mx1 = 0, mx2 = 0;
    m1[s[n - 1]]--;
    for (ll i = 0; i < n; i += 2) {
        m1[s[i]]++;
        if (m1[s[i]] > m1[mx1]) {
            mx1 = s[i];
        }
    }
    for (ll i = 1; i < n; i += 2) {
        m2[s[i]]++;
        if (m2[s[i]] > m2[mx1]) {
            mx2 = s[i];
        }
    }
    ans = min(ans, n - m1[mx1] - m2[mx2]);

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