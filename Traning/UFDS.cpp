class UFDS {
private:
    vector<int> parent, rank, size;
    vector<vector<int>> children;
    int numSets;

public:
    UFDS(int N) : numSets(N) {
        children.assign(N, vector<int>());
        rank.assign(N, 0);
        parent.assign(N, 0);
        size.assign(N, 1);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            children[i].push_back(i);
        }
    }

    int findSet(int i) {
        if (i < 0 || i >= parent.size()) return -1;  // Handle invalid index
        return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (x == -1 || y == -1) return;  // Handle invalid indices
            if (rank[x] > rank[y]) {
                parent[y] = x;
                size[x] += size[y];
                children[x].insert(children[x].end(), children[y].begin(), children[y].end());
                children[y].clear();
            } else {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
                size[y] += size[x];
                children[y].insert(children[y].end(), children[x].begin(), children[x].end());
                children[x].clear();
            }
            numSets--;
        }
    }

    vector<int> getChildrenOfSet(int i) {
        int root = findSet(i);
        return root != -1 ? children[root] : vector<int>();  // Handle invalid index
    }

    int sizeOfSet(int i) {
        int root = findSet(i);
        return root != -1 ? size[root] : 0;  // Handle invalid index
    }

    int numDisjointSets() {
        return numSets;
    }
};