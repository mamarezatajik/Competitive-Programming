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
ll a[maxN];

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
    cin >> m;
    UFDS uf (100000);
    map<string, int> idx;
    ll cnt = 0;

    for (ll i = 1; i <= m; i++) {
        string s, t;
        cin >> s >> t;
        if (!idx.count(s)) {
            idx[s] = cnt++;
        }
        if (!idx.count(t)) {
            idx[t] = cnt++;
        }

        uf.unionSet(idx[s], idx[t]);
        cout << uf.sizeOfSet(idx[s]) << '\n';
    }

    return 0;
}


signed main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}