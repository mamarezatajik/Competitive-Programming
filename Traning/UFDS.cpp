#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type,
less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


class UFDS {
private:
    vector<int> parent, rank, size;
    vector<ordered_set<int>> children;
    int numSets;

public:
    UFDS(int N) : numSets(N) {
        children.assign(N, ordered_set<int>());
        rank.assign(N, 0);
        parent.assign(N, 0);
        size.assign(N, 1);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            children[i].insert(i);
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
            if (x == -1 || y == -1) {
                return;  // Handle invalid indices
            }
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            else if (rank[x] == rank[y]) {
                rank[x]++;
            }
            parent[y] = x;
            size[x] += size[y];
            for (int child: children[y]) {
                children[x].insert(child);
            }
            children[y].clear();
            numSets--;
        }
    }

    ordered_set<int> getChildrenOfSet(int i) {
        int root = findSet(i);
        return root != -1 ? children[root] : ordered_set<int>();  // Handle invalid index
    }

    int sizeOfSet(int i) {
        int root = findSet(i);
        return root != -1 ? size[root] : 0;  // Handle invalid index
    }

    int numDisjointSets() {
        return numSets;
    }
};