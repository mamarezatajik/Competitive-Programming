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

const ll maxN = 2e2 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


int n, m, seen, slashNum, vis[maxN][maxN][4];
string s[maxN];
// 0 > R
// 1 > L
// 2 > U
// 3 > d


bool in(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, char c) {
    // cout << i << ", " << j << ", " << c << endl;
    ll ind;
    if (c == 'R') {
        ind = 0;
    } else if (c == 'L') {
        ind = 1;
    } else if (c == 'U') {
        ind = 2;
    } else {
        ind = 3;
    }
    // cout << i << ' ' << j << ' ' << c << endl;
    if (vis[i][j][ind]) {
        return;
    }
    vis[i][j][ind] = true;

    if (s[i][j] == '.') {
        if (c == 'R') {
            if (in(i, j + 1)) {
                dfs(i, j + 1, c);
            }
        } else if (c == 'L') {
            if (in(i, j - 1)) {
                dfs(i, j - 1, c);
            }
        } else if (c == 'U') {
            if (in(i - 1, j)) {
                dfs(i - 1, j, c);
            }
        } else {
            if (in(i + 1, j)) {
                dfs(i + 1, j, c);
            }
        }
        return;
    }

    int notSeen = 0;
    for (int k = 0; k < 4; k++) {
        if (vis[i][j][k]) {
            notSeen++;
        }
    }
    if (notSeen == 1) {
        seen++;
    }

    if (s[i][j] == '/') {
        if (c == 'R') { // move to U
            if (in(i - 1, j)) {
                dfs(i - 1, j, 'U');
            }
        } else if (c == 'L') { // move to D
            if (in(i + 1, j)) {
                dfs(i + 1, j, 'D');
            }
        } else if (c == 'U') { // move to L
            if (in(i, j + 1)) {
                dfs(i, j + 1, 'R');
            }
        } else { // if (c == 'D') // move to R
            if (in(i, j - 1)) {
                dfs(i, j - 1, 'L');
            }
        }
        return;
    }

    if (s[i][j] == '\\') {
        if (c == 'R') {
            if (in(i + 1, j)) {
                dfs(i + 1, j, 'D');
            }
        } else if (c == 'L') {
            if (in(i - 1, j)) {
                dfs(i - 1, j, 'U');
            }
        } else if (c == 'U') {
            if (in(i, j - 1)) {
                dfs(i, j - 1, 'L');
            }
        } else { // if (c == 'D')
            if (in(i, j + 1)) {
                dfs(i, j + 1, 'R');
            }
        }
        return;
    }

    assert(false);
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {  
                vis[i][j][k] = false;
            }
        }
    }
}


ll _main() {
    seen = slashNum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') {
                slashNum++;
            }
        }
    }

    vector<string> ans;
    // start from North;
    for (int j = 0; j < m; j++) {
        seen = 0;
        init();
        dfs(0, j, 'D');
        // cout << "------\n";
        // cout << seen << ' ' << slashNum << '\n';
        if (seen == slashNum) {
            string t = to_string(j + 1);
            ans.push_back('N' + t);
        }
    }

    // start from South;
    for (int j = 0; j < m; j++) {
        seen = 0;
        init();
        dfs(n - 1, j, 'U');
        // cout << seen << ' ' << slashNum << endl;
        if (seen == slashNum) {
            string t = to_string(j + 1);
            ans.push_back('S' + t);
        }
    }

    // start from West;
    for (int i = 0; i < n; i++) {
        seen = 0;
        init();
        dfs(i, 0, 'R');
        if (seen == slashNum) {
            string t = to_string(i + 1);
            ans.push_back('W' + t);
        }
    }

    // start from East;
    for (int i = 0; i < n; i++) {
        seen = 0;
        init();
        dfs(i, m - 1, 'L');
        if (seen == slashNum) {
            string t = to_string(i + 1);
            ans.push_back('E' + t);
        }
    }

    cout << len(ans) << endl;
    for (auto st: ans) {
        cout << st << ' ';
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