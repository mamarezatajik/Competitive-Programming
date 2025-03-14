#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll solve(ll i, ll j, vector<ll> a) {
    if (i == j) {
        return 1;
    }
    if (is_sorted(a.begin() + i, a.begin() + j)) {
        return j - i;
    }
    return max(solve(i, (i + j) / 2, a), solve((i + j) / 2, j, a));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    ll i = 0, j = n;
    cout << solve(i, j, a);
    return 0;
}