//HovalHaq!
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef pair<int, PII> PI3;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());


// PI3 getP(int x, int y, int z) {
//     vector<int> Point {
//         x % 10,
//         y % 10,
//         z % 10
//     };
//     sort(Point.begin(), Point.end());
//     return PI3(Point[0], PII(Point[1], Point[2]));
// }

int C2(int x) {
    return (x * (x - 1)) / 2;
}
int correct(int n, int m, vector<int> &A);
int solve(int n, int m, vector<int> &A, map<int, int> cnt);
int32_t main() {
    while (true) {
        // int n, m; cin >> n >> m;
        int n = rng() % 10 + 1, m = rng() % 10 + 1;
        vector<int> A(2 * n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            // cin >> A[i];
            A[i] = rng() % m + 1;
            cnt[A[i]]++;
            A[i + n] = A[i] + m;
        }
        // multiset<PI3> S;
        sort(A.begin(), A.end());
        int ans1 = correct(n, m, A);
        int ans2 = solve(n, m, A, cnt);

        if (ans1 != ans2) {
            cout << n << ' ' << m << endl;
            for (int i = 0; i < n; i++) {
                cout << A[i] << ' ';
            } cout << endl;
            cout << ans1 << ' ' << ans2 << endl;
            break;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //             S.insert({A[i], {A[j], A[k]}});
    //         }
    //     }
    // }
    // for (auto x: S) {
    //     cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    // }
    // cout << ans;

}

int correct(int n, int m, vector<int> &A) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) 
            for (int k = 0; k < j; k++) {
                vector<int> D {
                    abs(A[i] - A[j]),
                    abs(A[j] - A[k]),
                    abs(A[k] - A[i])
                };
                if (*min_element(D.begin(), D.end()) > 0 && 2 * *max_element(D.begin(), D.end()) > m) {
                    c++;
                    cout << A[i] << " " << A[j] << " " << A[k] << endl; 
                }}
        return c;
}

int solve(int n, int m, vector<int> &A, map<int, int> cnt) {
    
    int ans = n * (n - 1) * (n - 2) / 6;
    // cout << ans << endl;
    for (int i = 0; i < n; i++) {
        int l = A[i];
        int r = A[i] + m / 2 + 1;
        // if (m % 2 == 0 && l >= m / 2) r--;
        auto it = lower_bound(A.begin(), A.end(), r);
        int c = (it - A.begin()) - i - 1;
        ans -= C2(c);
        // cout << l << ": " << ((c * (c - 1)) / 2) << endl;
        // for (int j = i + 1; j <= (it - A.begin()) - 1; j++)
        //     for (int k = i + 1; k < j; k++) {
        //         auto kp = getP(A[i], A[j], A[k]);
        //         auto kooft = S.lower_bound(kp);
        //         if (*kooft != kp) {
        //             cout << A[i] << " " << A[k] << " " << A[j] << endl;
        //         } else {
        //             S.erase(kooft);
        //         }
        //     }
    }
    // cout << ans << endl;
    if (m % 2 == 0)
        for (int l = 1; l <= m / 2; l++) {
            // cout << l << " " << r << " " << cnt[l] * cnt[l + m / 2];
            ans += cnt[l] * C2(cnt[l + m / 2]);
            ans += cnt[l + m / 2] * C2(cnt[l]);
        }
    return ans;
}