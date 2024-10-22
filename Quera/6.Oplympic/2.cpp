#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e6 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r, ans, a, b;

ll _main() {
    cin >> n;
    ans = 0;

    for (int a = 1; a * a < n; ++a) {  
        if (n % a == 0) {  
            int b = n / a;  
            if ((a + b) % 2 == 0 && (b - a) % 2 == 0) {  
                x = (a + b) / 2;  
                y = (b - a) / 2;  
                if (x > 0 && y > 0) {  
                    ans++;  
                }  
            }  
        }  
    } 

    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}