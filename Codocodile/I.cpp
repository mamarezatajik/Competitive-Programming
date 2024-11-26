//HovalHaq!

#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int s, c; cin >> s >> c;
    int x = min(s / 2, c);
    c -= x;
    s -= 2 * x;
    if (s == 0) x += c / 5;
    else if (c >= 3) {
        c += 2;
        x += c / 5;
    }
    cout << x << endl;
}