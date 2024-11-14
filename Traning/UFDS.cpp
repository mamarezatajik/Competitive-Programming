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