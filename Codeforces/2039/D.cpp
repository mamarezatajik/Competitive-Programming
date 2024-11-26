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

const ll maxN = 3e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN];
pll lpd[maxN], ans[maxN];
vector<ll> primes;

void sieve() {
    for (int i = 2; i < 3e5 + 9; i++) {
        if (lpd[i].F == 0) {
            lpd[i] = {i, i};
            primes.push_back(i);
        }
        for (ll prime: primes) {
            if (i * prime >= 1e5 + 8) {
                break;
            }
            lpd[i * prime] = {i, prime};
            if (prime == lpd[i].F || prime == lpd[i].S) {
                break;
            }
        }
    }
}



ll _main() {
    cin >> m >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (ll i = 1; i <= m; i++) {
        ans[i].F = ans[i].S = 0;
    }


    ans[1].F = a[n];
    ans[1].S = n;
    ll ptr = n - 1, idx;
    for (ll i = 2; i <= m; i++) {
        if (ptr == 0) {
            break;
        }
        if (lpd[i].F == i) {
            ans[i] = {a[ptr], ptr};
        } 
        else {
            auto [leftVal, leftIdx] = ans[lpd[i].F];
            auto [rightVal, rightIdx] = ans[lpd[i].S];

            if (leftIdx == 1 || rightIdx == 1) {
                return cout << "-1\n", 0;
            }

            if (leftVal < rightVal) {
                ans[i] = {a[leftIdx - 1], leftIdx - 1};
            } else {
                ans[i] = {a[rightIdx - 1], rightIdx - 1};
            }
        }
    }

    for (ll i = 1; i <= m; i++) {
        if (ans[i].F == 0) {
            return cout << "-1\n", 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i].F << " \n"[i == m];
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}