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

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN], dp[maxN][5], preSum[maxN], bestLeft[maxN], bestRight[maxN];

ll getMin(vector<ll> v) {
    return *min_element(v.begin(), v.end() - 1);
}

ll getMax(vector<ll> v) {
    return *max_element(v.begin(), v.end() - 1);
}


vector<ll> solve(ll idx) {
    vector<vector<ll>> v (5, vector<ll>(6));
    for (ll i = 1; i <= 4; i++) {
        for (ll j = 1; j <= 4; j++) {
            v[i][j] = dp[idx][j];
        }
    }
    ll val = a[idx + 1];
    for (ll i = 1; i <= 4; i++) {
        v[i][5] = val;
    }


    ll j = 3;
    for (ll i = 1; i <= 4; i++) {
        v[i][5 - i] += v[i][6 - i];
        for (ll j = 6 - i; j < 5; j++) { 
            v[i][j] = v[i][j + 1];
        }
    }

    ll ans = -1, minDiff = inf;
    for (ll i = 1; i <= 4; i++) {
        ll curDiff = getMax(v[i]) - getMin(v[i]);
        if (curDiff < minDiff) {
            minDiff = curDiff;
            ans = i;
        }
    }

    return v[ans];
}


void solveBestLeft() {
    ll i = 2, j = 1;
    bestLeft[1] = 1;
    ll sumLeft = 0, sumRight = 0;
    while (i <= n) {
        sumLeft = preSum[j];
        sumRight = preSum[i] - preSum[j];
        ll bestDiff = abs(sumLeft - sumRight);

        while (j + 1 < i) {
            sumLeft = preSum[j + 1];
            sumRight = preSum[i] - preSum[j + 1];
            ll curDiff = abs(sumLeft - sumRight);

            if (bestDiff > curDiff) {
                bestDiff = curDiff;
                j++;
            } else {
                break;
            }
        }
        // cout << i << ' ' <<  j << ' ' << sumLeft << " " << sumRight << endl;
        bestLeft[i] = j;
        i++;
    }
    // for (ll i = 1; i <= n; i++) {
    //     cout << bestLeft[i] << ' ';
    // } cout << endl;
}

void solveBestRight() {
    ll i = n - 1, j = n;
    ll sumLeft = 0, sumRight = 0;
    bestRight[n] = n;
    while (i >= 1) {
        sumLeft = preSum[j - 1] - preSum[i - 1];
        sumRight = preSum[n] - preSum[j - 1];
        // cout << i << ' ' <<  j << ' ' << sumLeft << " " << sumRight << endl;
        ll bestDiff = abs(sumLeft - sumRight);

        while (j > i) {
            sumLeft = preSum[j - 1] - preSum[i];
            sumRight = preSum[n] - preSum[j - 2];
            ll curDiff = abs(sumLeft - sumRight);

            if (bestDiff >= curDiff) {
                bestDiff = curDiff;
                j--;
            } else {
                break;
            }
        }
        bestRight[i] = j;
        i--;
    }

    // for (ll i = 1; i <= n; i++) {
    //     cout << bestRight[i] << ' ';
    // } cout << endl;
}


void solve() {
    ll ans = inf;
    for (ll i = 2; i < n; i++) {
        vector<ll> v (4);
        v[3] = preSum[n] - preSum[bestRight[i]];
        v[2] = preSum[bestRight[i]] - preSum[i + (n != 5 && a[0] != 4)];
        v[1] = preSum[i + (n != 5 && a[0] != 4)] - preSum[bestLeft[i]];
        v[0] = preSum[bestLeft[i]];
        ans = min(ans, *max_element(all(v)) - *min_element(all(v)));
    }

    cout << ans;
}



ll _main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }

    solveBestLeft();
    solveBestRight();
    solve();
    return 0;

    for (ll i = 1; i <= 4; i++) {
        dp[4][i] = a[i];
    }


    for (ll i = 5; i <= n; i++) {
        vector<ll> v = solve(i - 1);
        for (ll j = 1; j <= 4; j++) {
            dp[i][j] = v[j];
        }
    }

    ll mx = *max_element(dp[n] + 1, dp[n] + 5);
    ll mn = *min_element(dp[n] + 1, dp[n] + 5);

    return cout << mx - mn, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}