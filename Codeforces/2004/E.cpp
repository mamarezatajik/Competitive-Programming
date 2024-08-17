#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e7 + 100;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

ll lpd[maxN] = {0}, idx[maxN];
vector<ll> pr;

void linearSieve() {
    pr.clear();
    for (ll i = 2; i < maxN; i++) {
        if (lpd[i] == 0) {
            lpd[i] = i;
            pr.push_back(i);
        }
        for (ll p : pr) {
            if (i * p > maxN)
                break;
            lpd[i * p] = p;
            if (p == lpd[i])
                break;
        }
    }
    for (ll i = 0; i < len(pr); i++)
        idx[pr[i]] = i + 1;
}

ll grundyValue(ll n) {
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return 0;
    return idx[lpd[n]];
}

ll _main() {
    ll n; cin >> n;

    ll ans = 0;
    for (ll cur, i = 0; i < n; i++) {
        cin >> cur;
        ans ^= grundyValue(cur);
    }

    if (ans)
        cout << "Alice";
    else
        cout << "Bob";

    return cout << '\n', 0;
}


signed main() {
    linearSieve();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}