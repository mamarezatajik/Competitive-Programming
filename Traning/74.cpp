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


int n, m, k, q, u, v, w, x, y, z, l, r, cnt;

class UFDS {
private:
	vector<int> parent, rank, size;
    vector<vector<int>> children;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
        children.assign(N, vector<int>());
		rank.assign(N, 0);
		parent.assign(N, 0);
		for (int i = 0; i < N; i++) {
			parent[i] = i;
            children[i].push_back(i);
        }
		size.assign(N, 1);
	}
	int findSet(int i) {
		return (parent[i] == i) ? i : parent[i] = findSet(parent[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				parent[y] = x;
				size[x] += size[y];
                for (int child: children[y]) {
                    children[x].push_back(child);
                } children[y].clear();
			} else {
				parent[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
				size[y] += size[x];
                for (int child: children[x]) {
                    children[y].push_back(child);
                } children[x].clear();
			}
			numSets--;
		}
	}
    vector<int> childrenOfSet(int i) {
        return children[findSet(i)];
    }
    int sizeOfSet(int i) {
        return size[findSet(i)];
    }
	int numDisjointSets() {
		return numSets;
	}
};

ll _main() {
    while (cin >> n) {
        cin >> m;
        vector<int> adj[26];
        map<char, ll> idx;

        string s;
        cin >> s;
        cnt = 0;

        for (int i = 0; i < 3; i++) {
            idx[s[i]] = cnt++;
        }

        UFDS uf (26);
        uf.unionSet(0, 1);
        uf.unionSet(1, 2);


        for (ll i = 1; i <= m; i++) {
            cin >> s;
            if (!idx.count(s[0])) {
                idx[s[0]] = cnt++;
            }
            if (!idx.count(s[1])) {
                idx[s[1]] = cnt++;
            }
            adj[idx[s[0]]].push_back(idx[s[1]]);
            adj[idx[s[1]]].push_back(idx[s[0]]);
        }


        int ans = 0;
        while (true) {
            bool end = true;
            vector<int> toAdd;
            for (int i = 3; i < n; i++) {
                if (uf.isSameSet(i, 0)) {
                    continue;
                }

                int ctr = 0;
                for (int v: adj[i]) {
                    ctr += uf.isSameSet(v, 0);
                }
                if (ctr >= 3) {
                    toAdd.push_back(i);
                    end = false;
                }
            }

            if (end) {
                break;
            }

            for (int v: toAdd) {
                uf.unionSet(v, 0);
            }
            ans++;
        }

        if (uf.sizeOfSet(0) == n) {
            cout << "WAKE UP IN, " << ans << ", YEARS\n";
        } else {
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
    }

    return 0;
}


signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}