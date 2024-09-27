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
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    ll ans = 0;
    for (ll i = 1; i < n - 1; i++) {
        if (s[i - 1] == 'A' &&
            s[i] == 'B' &&
            s[i + 1] == 'C') {
                ans++;
            }
    }

    for (ll i = 0; i < q; i++) {
        ll x; char c;
        cin >> x >> c;
        x--;

        if (s[x] == 'A' && c != 'A') {
            if (x + 2 < n) {
                if (s[x + 1] == 'B') {
                    if (s[x + 2] == 'C') {
                        ans--;
                    } 
                }
            }
        }
        else if (s[x] == 'B' && c != 'B') {
            if (0 <= x - 1 && x + 1 < n) {
                if (s[x - 1] == 'A') {
                    if (s[x + 1] == 'C') {
                            ans--;
                    }
                }
            }
        }
        else if (s[x] == 'C' && c != 'C') {
            if (0 <= x - 2) {
                if (s[x - 2] == 'A') {
                    if (s[x - 1] == 'B') {
                        ans--;
                    }
                }
            }
        }

        if (0 <= x - 1 && x + 1 < n) {
            if (s[x - 1] == 'A') {
                if (s[x + 1] == 'C') {
                    if (s[x] != c && c == 'B') {
                        ans++;
                    }
                }
            }
        }
        if (x + 2 < n) {
            if (s[x + 1] == 'B') {
                if (s[x + 2] == 'C') {
                    if (s[x] != c && c == 'A') {
                        ans++;
                    }
                } 
            }
        }
        if (0 <= x - 2) {
            if (s[x - 2] == 'A') {
                if (s[x - 1] == 'B') {
                    if (s[x] != c && c == 'C') {
                        ans++;
                    }
                }
            }
        }

        s[x] = c;
        cout << ans << '\n';
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}