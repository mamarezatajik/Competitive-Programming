#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 100 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll swapLR = -1, swapUD = -1, n, m, vis[maxN][maxN], qx, qy, found = false;
string grid[maxN];
pll nxt[maxN][maxN], pre[maxN][maxN];

void query(char c) {
    cout << c << endl;
    cin >> qx >> qy;
    qx--, qy--;
}

bool canMoveL(ll i, ll j) {
    if (0 < j && grid[i][j - 1] != '*') {
        return true;
    }
    return false;
}

bool canMoveR(ll i, ll j) {
    if (j + 1 < m && grid[i][j + 1] != '*') {
        return true;
    }
    return false;
}

bool canMoveU(ll i, ll j) {
    if (0 < i && grid[i - 1][j] != '*') {
        return true;
    }
    return false;
}

bool canMoveD(ll i, ll j) {
    if (i + 1 < n && grid[i + 1][j] != '*') {
        return true;
    }
    return false;
}

void findF(ll i, ll j) {
    if (found) {
        return;
    }
    if (grid[i][j] == 'F') {
        qx = i;
        qy = j;
        found = true;
        return ;
    }

    vis[i][j] = true;

    if (canMoveR(i, j) && !vis[i][j + 1]) {
        pre[i][j + 1] = {i, j};
        findF(i, j + 1);
    }
    if (canMoveL(i, j) && !vis[i][j - 1]) {
        pre[i][j - 1] = {i, j};
        findF(i, j - 1);
    }
    if (canMoveU(i, j) && !vis[i - 1][j]) {
        pre[i - 1][j] = {i, j};
        findF(i - 1, j);
    }
    if (canMoveD(i, j) && !vis[i + 1][j]) {
        pre[i + 1][j] = {i, j};
        findF(i + 1, j);
    }
}


void dfs(ll i, ll j) {
    auto [x, y] = nxt[i][j];
    bool ok = false;

    if (x == i + 1) {
        if (swapUD == -1) {
            query('U');
            swapUD = i + 1 == qx;
            ok = swapUD == 1;
        }
        if (ok) {
            
        }
        else if (!swapUD) {
            query('D');
        }
        else {
            query('U');
        }
    }

    else if (x == i - 1) {
        if (swapUD) {
            query('D');
        }
        else {
            query('U');
        }
    }

    else if (y == j + 1) {
        if (swapLR == -1) {
            query('L');
            swapLR = j + 1 == qy;
            ok = swapLR == 1;
        }
        if (ok) {
            
        }
        else if (swapLR) {
            query('L');
        }
        else {
            query('R');
        }
    }

    else {
        if (!swapLR) {
            query('L');
        }
        else {
            query('R');
        }
    }

    if (grid[x][y] == 'F') {
        return ;
    }

    dfs(x, y);
}


ll _main() {
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    findF(0, 0);
    while (true) {
        pll tmp = pre[qx][qy];
        nxt[tmp.F][tmp.S] = {qx, qy};
        qx = tmp.F, qy = tmp.S;
        if (qx == qy && qx == 0) {
            break;
        }
    }

    dfs(0, 0);

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}