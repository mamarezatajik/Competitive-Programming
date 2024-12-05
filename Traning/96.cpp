#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<int, int>        pii;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 1e3 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


int n, m;
string s[maxN];
int isTrap[maxN][maxN], vis[maxN][maxN];

string gen_random(const int len) {
    static const char alphanum[] =
        "UDLR?";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}

bool isInMaze(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

ll dfs(int i, int j) {
    if (vis[i][j]) {
        if (isTrap[i][j] == 0) { // it has road to go out;
            return 0;
        }
        return 1; // there is a self loop;
    }
    vis[i][j] = true;


    if (s[i][j] == 'R') {
        if (isInMaze(i, j + 1)) {
            return isTrap[i][j] = dfs(i, j + 1);
        } else {
            return isTrap[i][j] = 0; // this component is not trap;
        }
    }
    else if (s[i][j] == 'L') {
        if (isInMaze(i, j - 1)) {
            return isTrap[i][j] = dfs(i, j - 1);
        } else {
            return isTrap[i][j] = 0;
        }
    }
    else if (s[i][j] == 'U') {
        if (isInMaze(i - 1, j)) {
            return isTrap[i][j] = dfs(i - 1, j);
        } else {
            return isTrap[i][j] = 0;
        }
    }
    else if (s[i][j] == 'D') {
        if (isInMaze(i + 1, j)) {
            return isTrap[i][j] = dfs(i + 1, j);
        } else {
            return isTrap[i][j] = 0;
        }
    }
    else { // s[i][j] == '?' :
        ll notTrap = 0;
        if (isInMaze(i, j + 1)) {
            dfs(i, j + 1);
            if (s[i][j + 1] == 'L' || s[i][j + 1] == '?' || isTrap[i][j + 1] == 1) {
                s[i][j] = 'R';
                s[i][j + 1] = 'L';
                return isTrap[i][j] = 1;
            }
            notTrap += isTrap[i][j + 1] == 0;
        } else {
            notTrap++;
        }
        if (isInMaze(i, j - 1)) {
            dfs(i, j - 1);
            if (s[i][j - 1] == 'R' || s[i][j - 1] == '?' || isTrap[i][j - 1] == 1) {
                s[i][j] = 'L';
                s[i][j - 1] = 'R';
                return isTrap[i][j] = 1;
            }
            notTrap += isTrap[i][j - 1] == 0;
        } else {
            notTrap++;
        }
        if (isInMaze(i + 1, j)) {
            dfs(i + 1, j);
            if (s[i + 1][j] == 'U' || s[i + 1][j] == '?' || isTrap[i + 1][j] == 1) {
                s[i][j] = 'D';
                s[i + 1][j] = 'U';
                return isTrap[i][j] = 1;
            }
            notTrap += isTrap[i + 1][j] == 0;
        } else {
            notTrap++;
        }
        if (isInMaze(i - 1, j)) {
            dfs(i - 1, j);
            if (s[i - 1][j] == 'D' || s[i - 1][j] == '?' || isTrap[i - 1][j] == 1) {
                s[i][j] = 'U';
                s[i - 1][j] = 'D';
                return isTrap[i][j] = 1;
            }
            notTrap += isTrap[i - 1][j] == 0;
        } else {
            notTrap++;
        }
        if (notTrap == 4) {
            return isTrap[i][j] = 0; // never can make a trap;
        }
    }

    return -1;
}

ll _main() {
    cin >> n >> m;
    // while (true) {
    // n = rng() % 10 + 1;
    // m = rng() % 10 + 1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        // s[i] = gen_random(m);
        for (int j = 0; j < m; j++) {
            isTrap[i][j] = -1; // -1 ---> not visited yet
            vis[i][j] = false;
        }
    }

    // try
    // {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    dfs(i, j);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += isTrap[i][j];
            }
        }

        // cout << ans << endl;
    // }
    // catch(const std::exception& e)
    // {
    //     cout << n << ' ' << m << '\n';
    //     for (int i = 0; i < n; i++) {
    //         cout << s[i] << '\n';
    //     }
    // }
    // }
    return cout << ans << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}