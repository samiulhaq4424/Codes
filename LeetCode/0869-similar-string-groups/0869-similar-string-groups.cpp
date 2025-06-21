class UnionFind {
public:
    int count;
    vector<int> root, rank;
    UnionFind(int n) {
        count = n;
        root.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }
    int findRoot(int node) {
        if (root[node] == node) return node;
        return root[node] = findRoot(root[node]);
    }
    void mergeByRank(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB) return;
        if (rank[rootA] > rank[rootB]) {
            root[rootA] = rootB;
            rank[rootB] += rank[rootA];
        } else {
            root[rootB] = rootA;
            rank[rootA] += rank[rootB];
        }
        count--;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& words) {
        int n = words.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rootI = uf.findRoot(i), rootJ = uf.findRoot(j);
                if (rootI == rootJ) continue;

                if (words[i] == words[j]) {
                    uf.mergeByRank(i, j);
                } else {
                    int diffCount = 0;
                    for (int k = 0; k < words[i].size(); k++) {
                        if (words[i][k] != words[j][k]) {
                            if (++diffCount > 2) break;
                        }
                    }
                    if (diffCount == 2) uf.mergeByRank(i, j);
                }
            }
        }
        return uf.count;
    }
};