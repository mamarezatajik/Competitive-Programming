#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        long long n, p, k;
        cin >> n >> p >> k;

        long long order = p % k;
        long long sum = order * n;
        sum /= ((order * (order + 1)) / 2);
        sum += (p / k) + 1;

        cout << sum << '\n';
    }
}