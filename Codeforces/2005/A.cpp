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
vector<char> c = {'a', 'e', 'i', 'o', 'u'};


ll _main() {
    ld n; cin >> n;
    ld cnt = 1;

    for (ll i = 1; i <= n; i++) {
        cout << c[(((ll) cnt) - 1)];
        if (i >= (n * cnt / 5.0)) {
            cnt++;
        }
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