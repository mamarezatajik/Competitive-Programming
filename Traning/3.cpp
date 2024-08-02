#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        ll cost, n; string vitamin;
        cin >> n; ll A, B, C, AB, AC, BC, ABC;
        A = B = C = AB = AC = BC = ABC = inf;
        bool a = false, b = false, c = false;
        for (int i = 0; i < n; i++) {
            cin >> cost >> vitamin;
            sort(vitamin.begin(), vitamin.end());
            if (vitamin == "A")        A = min(A, cost), a = true;
            else if (vitamin == "B")   B = min(B, cost), b = true;
            else if (vitamin == "C")   C = min(C, cost), c = true;
            else if (vitamin == "AB") AB = min(AB, cost), a = b = true;
            else if (vitamin == "AC") AC = min(AC, cost), a = c = true;
            else if (vitamin == "BC") BC = min(BC, cost), b = c = true;
            else                     ABC = min(ABC, cost), a = b = c = true;
        }

        if (!a || !b || !c)
            cout << "-1";
        else
            cout << min({
                A + B + C,
                AB + C, AB + BC,
                AC + B, AC + BC,
                A + BC, AB + AC,
                ABC
            });
    }
    return 0;
}