#include <bits/stdc++.h>
using namespace std;

signed main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n, m, x, y, s;
        cin >> n >> m >> x >> y >> s;

        bool openTop = 1 < x - s;
        bool openLeft = 1 < y - s;
        bool openBot = x + s < n;
        bool openRight = y + s < m;

        if ((openLeft && openBot) ||
            (openTop && openRight)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
    }
    return 0;
}