//HovalHaq!
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef pair<int, PII> PI3;

PI3 getP(int x, int y, int z) {
    vector<int> Point {
        x % 10,
        y % 10,
        z % 10
    };
    sort(Point.begin(), Point.end());
    return PI3(Point[0], PII(Point[1], Point[2]));
}

int C2(int x) {
    return (x * (x - 1)) / 2;
}

int32_t main() {
    int n, m; cin >> n >> m;
    vector<int> A(2 * n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
        A[i + n] = A[i] + m;
    }
    sort(A.begin(), A.end());
    multiset<PI3> S;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                S.insert({A[i], {A[j], A[k]}});
            }
        }
    }
     for (auto x: S) {
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }
    int ans = n * (n - 1) * (n - 2) / 6;
    // cout << ans << endl;
    for (int i = 0; i < n; i++) {
        int l = A[i];
        int r = A[i] + m / 2 + 1;
        // if (m % 2 == 0 && l >= m / 2) r--;
        auto it = lower_bound(A.begin(), A.end(), r);
        int c = (it - A.begin()) - i - 1;
        ans -= C2(c);
        cout << l << ": " << ((c * (c - 1)) / 2) << endl;
        for (int j = i + 1; j <= (it - A.begin()) - 1; j++)
            for (int k = i + 1; k < j; k++) {
                auto kp = getP(A[i], A[j], A[k]);
                auto kooft = S.lower_bound(kp);
                if (*kooft != kp) {
                    cout << A[i] << " " << A[k] << " " << A[j] << endl;
                } else {
                    cout << A[i] << " " << A[k] << " " << A[j] << " CORECT" << endl;
                    S.erase(kooft);
                }
            }
    }
    // cout << ans << endl;
    if (m % 2 == 0)
        for (int l = 1; l <= m / 2; l++) {
            // cout << l << " " << r << " " << cnt[l] * cnt[l + m / 2];
            ans += cnt[l] * C2(cnt[l + m / 2]);
            ans += cnt[l + m / 2] * C2(cnt[l]);
        }
    cout << ans << endl;
    for (auto x: S) {
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }
    // cout << ans;

}