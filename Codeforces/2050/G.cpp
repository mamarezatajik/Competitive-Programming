#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define len(a) (ll)(a.size())
#define all(a) (a).begin(), (a).end()

const ll maxN = 2e5 + 10;

vector<vector<int>> adj;
vector<int> subtree_size;
int n;

// DFS to calculate the size of the subtree for each node
void dfs(int node, int parent) {
    subtree_size[node] = 1; // Start with size 1 (counting the node itself)
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // Avoid going back to the parent
        dfs(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
    }
}

ll _main() {
    cin >> n;

    // Initialize adjacency list and subtree size array
    adj.assign(n + 1, vector<int>());
    subtree_size.assign(n + 1, 0);

    // Read the tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Compute subtree sizes
    dfs(1, -1);

    // Find the maximum number of connected components
    int max_components = 1; // At least one component initially
    for (int node = 1; node <= n; node++) {
        int components = 1; // One component for the root of the tree
        for (int neighbor : adj[node]) {
            // If the neighbor is part of a subtree (child of the current node)
            if (subtree_size[neighbor] < subtree_size[node]) {
                components += subtree_size[neighbor];
            } else {
                // Add the rest of the tree excluding this subtree
                components += (n - subtree_size[node]);
            }
        }
        max_components = max(max_components, components);
    }

    cout << max_components << '\n';
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}