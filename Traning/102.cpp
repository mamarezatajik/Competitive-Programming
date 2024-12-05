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


ll n, m, idx;
vector<string> a;
string ans, s;


void BtoD(int l, int r, int u, int d) {
    if (l == r || u == d) {
        return;
    }
    if (l + 1 == r && u + 1 == d) {
        ans += a[u][l];
        return ;
    }

    bool isOne = true;
    bool isZero = true;
    for (int i = u; i < d; i++) {
        for (int j = l; j < r; j++) {
            isOne &= a[i][j] == '1';
            isZero &= a[i][j] == '0';
        }
    }

    if (isOne) {
        ans += '1';
        return;
    }
    if (isZero) {
        ans += '0';
        return;
    }

    ans += 'D';
    int midLR = (l + r + 1) / 2;
    int midUD = (u + d + 1) / 2;
    BtoD(l, midLR, u, midUD);
    BtoD(midLR, r, u, midUD);
    BtoD(l, midLR, midUD, d);
    BtoD(midLR, r, midUD, d);
}

void DtoB(int l, int r, int u, int d) {
    if (idx == len(s) || l == r || u == d) {
        return;
    }
    if (s[idx++] != 'D') {
        for (int i = u; i < d; i++) {
            for (int j = l; j < r; j++) {
                a[i][j] = s[idx - 1];
            }
        }
        return;
    }

    int midLR = (l + r + 1) / 2;
    int midUD = (u + d + 1) / 2;
    DtoB(l, midLR, u, midUD);
    DtoB(midLR, r, u, midUD);
    DtoB(l, midLR, midUD, d);
    DtoB(midLR, r, midUD, d);
}


ll _main() {
    char c;
    while (cin >> c) {
        if (c == '#') {
            break;
        }
        idx = 0;
        ans = "";
        cin >> n >> m;

        cin >> s;
        cout << (c == 'B' ? 'D': 'B') << ' ' << n << ' ' << m << '\n';

        int k = 0;
        if (c == 'B') {
            a.resize(n);
            for (int i = 0; i < n; i++) {
                string t = "";
                for (int j = 0; j < m; j++) {
                    t += s[k++];
                }
                a[i] = t;
            }
            BtoD(0, m, 0, n);
        } else {
            a.resize(n, string('0', m));
            DtoB(0, m, 0, n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans += a[i][j];
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << a[i][j] << ' ';
        //     } cout << endl;
        // }
        cout << ans << endl;
    }

    return 0;
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