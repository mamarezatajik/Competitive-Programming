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

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
set<char> vowel {'A', 'E', 'I', 'O', 'U'};

string random(int len) {
    string s = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string res;
    for (int i = 0; i < len; i++) {
        res += s[rng() % 26];
    }
    return res;
}


ll _main() {
    // while (true) {
    // 0 -> number of Y;
    // 1 -> number of vowel - Y;
    // 2 -> number of consonant - NG;
    // 3 -> number of NG
    // 4 -> number of N
    // 5 -> number of G
    vector<int> data (6);
    string s = random(rng() % 10 + 1); 
    cin >> s; 
    // cout << s << '\n';
    n = len(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y') {
            data[0]++;
        } else if (vowel.count(s[i])) {
            data[1]++;
        } else if (s[i] == 'N') {
            data[4]++;
        } else if (s[i] == 'G') {
            data[5]++;
        } else {
            data[2]++;
        }
    }

    data[3] = min(data[4], data[5]);
    data[4] -= data[3];
    data[5] -= data[3];
    data[2] += data[4] + data[5];

    // for (int i = 0; i < 4; i++) {
    //     cout << "i = " << i << " -- " << data[i] << endl;
    // }

    // 0 -> number of Y;
    // 1 -> number of vowel - Y;
    // 2 -> number of consonant - NG;
    // 3 -> number of NG
    int ans = -1, useNG = 0; 
    bool end = false;
    while (!end) {
        end = true;
        int val = data[0] + data[2] + 2 * data[3];
        // cout << val << endl;
        if (val <= 2 * data[1]) {
            ans = (val / 2) * 2 + (val / 2) + useNG;
            if (val % 2 == 1 && data[3]) {
                ans++;
            }
        }
        else { // (val > 2 * data[1])
            if (data[0]) { // if we have Y
                data[0]--;
                if (val - 1 >= 2 * (data[1] + 1)) { // change Y from cons to vowel;
                    data[1]++;
                } else {                            // change Y to consonant;
                    data[2]++;
                }
                end = false;
            }
            else if (data[3]) { // use NG as one cons;
                data[3]--;
                useNG++;
                data[2]++;
                end = false;
            }
        }
    }

    // 0 -> number of Y;
    // 1 -> number of vowel - Y;
    // 2 -> number of consonant - NG;
    // 3 -> number of NG
    if (ans == -1) {
        // cout << s << '\n';
        // assert(data[0] == 0 && data[3] == 0);
        ans = useNG + min(3 * data[1], (data[2] / 2) * 2 + (data[2] / 2));
        if (data[1] == 0 || data[2] == 0) {
            ans = 0;
        }
        // if (0 < ans && ans < 3) {
        //     cout << s;
        //     break;
        // }
    } 
// }

    return cout << ans << endl, 0;
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