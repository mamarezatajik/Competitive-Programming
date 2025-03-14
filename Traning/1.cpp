#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(a) (ll) (a.size())
#define F first
#define S second

const ll maxN = 5e2 + 10;
const ll inf = 1e9 +  10;


ll n, m, isSafe = true, dp[maxN][maxN], vis[maxN][maxN];
string s[maxN];
set<pair<ll, pll>> pos;
ll dx[] = {0, 0, -1, 1};
ll dy[] = {-1, 1, 0, 0};

bool check1(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < m && 
                s[i][j] != '*' && s[i][j] != '#';
}

bool check2(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void dijkstra(pll src) {
    ll x = src.F, y = src.S;
    priority_queue<array<ll, 4>> pq;
    pq.push({dp[x][y], x, y, min(dp[x][y], inf)});

    while (!pq.empty()) {
        auto [dist, i, j, nearest] = pq.top();
        pq.pop();
        if (s[i][j] == 'E') {
            if (isSafe) {
                cout << "safe";
            } else {
                cout << nearest;
            }
            exit(0);
        }

        if (vis[i][j]) {
            continue;
        }

        array<ll, 4> arr;
        for (ll x = 0; x < 4; x++) {
            ll I = i + dx[x];
            ll J = j + dy[x];
            if (check1(I, J) && !vis[I][J]) {
                arr = {dp[I][J], I, J, min(nearest, dp[I][J])};
                pq.push(arr);
            }
        }
        vis[i][j] = true;
    }
}

pair<ll, pll> bug(ll i, ll j) {
    pair<ll, pll> res = {inf, {-1, -1}};
    for (ll I = 0; I < n; I++) {
        for (ll J = 0; J < m; J++) {
            if (s[I][J] == '*') {
                if (res.F > max(abs(i - I), abs(j - J))) {
                    res = {max(abs(i - I), abs(j - J)), {I, J}};
                }
            }
        }
    }
    return res;
}

void dfs(set<array<ll, 3>> st) {
    while (!st.empty()) {
        auto [val, i, j] = *st.begin();
        st.erase(st.begin());

        if (dp[i][j] < val) {
            continue;
        }
        dp[i][j] = val;

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                ll I = i + dx[x];
                ll J = j + dy[y];
                if (check2(I, J)) {
                    st.insert({val + 1, I, J});
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // ifstream cin("zzz.txt");

    cin >> n >> m;
    pair<ll, ll> src = {-1, -1};
    set<array<ll, 3>> st;
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
        for (ll j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                src = {i, j};
            }
            if (s[i][j] == '*') {
                st.insert({0, i, j});
                isSafe = false;
            }
        }
    }
    if (src.F == -1) {
        return cout << -1, 0;
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            dp[i][j] = inf;
        }
    }

    dfs(st);
    dijkstra(src);
    return cout << -1, 0;
}