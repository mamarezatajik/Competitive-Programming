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
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


vector<vector<int>> e;  
vector<int> dp, max_dp, ct, ct2;  
vector<bool> vis;  

void dfs(int u) {  
    vis[u] = true;  
    max_dp[u] = dp[u];  
    for (int v : e[u]) {  
        if (vis[v]) {  
            continue;  
        }  
        dp[v] = dp[u] + 1;  
        dfs(v);  
        max_dp[u] = max(max_dp[u], max_dp[v]);  
    }  
}  

int main() {  
    int t;  
    cin >> t;  

    while (t--) {  
        int n;  
        cin >> n;  

        e.assign(n + 3, vector<int>());  
        dp.assign(n + 3, 0);  
        max_dp.assign(n + 3, 0);  
        ct.assign(n + 3, 0);  
        ct2.assign(n + 3, 0);  
        vis.assign(n + 3, false);  

        for (int i = 1; i < n; i++) {  
            int a, b;  
            cin >> a >> b;  
            e[a].push_back(b);  
            e[b].push_back(a);  
        }  

        dfs(1);  

        for (int i = 1; i <= n; i++) {  
            ct[dp[i]]++;  
            ct2[max_dp[i]]++;  
        }  

        int res = numeric_limits<int>::max();  
        int a = 0;  
        int b = accumulate(ct.begin() + 1, ct.begin() + n + 1, 0);  

        for (int i = 1; i <= n; i++) {  
            b -= ct[i];  
            res = min(res, a + b);  
            a += ct2[i];  
        }  

        cout << res << '\n';  
    }  

    return 0;  
}