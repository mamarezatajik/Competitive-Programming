#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 3e5 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll a[maxN], b[maxN];


ll _main() {
    ll n; cin >> n;

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < n; i++) 
        cin >> b[i];

    ll lBob = 0, rBob = n - 1;
    ll lAlice = 0, rAlice = n - 1;

    bool win = true;

    while (win && lAlice < rAlice && lBob < rBob) {
        if (a[lAlice] == b[lBob] || a[lAlice] == b[rBob]) {
            if (!(a[rAlice] == b[lBob] || a[rAlice] == b[rBob])) {
                win = false;
            }
            else {
                if (a[rAlice] == b[rBob])
                    rBob--;
                else
                    lBob++;
                rAlice--;
            }
        }
        else
            win = false;
    }

    return cout << (win ? "Bob": "Alice") << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
        _main();

    return 0;
}