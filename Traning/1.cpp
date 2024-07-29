#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        if (n < 2) {
            cout << 1 << '\n';
            continue;
        }

        long long first = 0;
	    long long last = (n - 2) * 2;
	    long long sum = 1 + ((last - first) / 2) * (n - 1);
        cout << sum << '\n';
	}
}