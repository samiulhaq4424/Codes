class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int ind = 0; ind < 4; ind++) {
                        int ni = i + dr[ind];
                        int nj = j + dc[ind];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int node = i * n + j;
                            int adjNode = ni * n + nj;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    for (int ind = 0; ind < 4; ind++) {
                        int ni = i + dr[ind];
                        int nj = j + dc[ind];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            st.insert(ds.findParent(ni * n + nj));
                        }
                    }
                    int totalSize = 0;
                    for (auto it : st) {
                        totalSize += ds.size[it];
                    }
                    maxi = max(maxi, totalSize + 1);
                }
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxi = max(maxi, ds.size[ds.findParent(cellNo)]);
        }
        return maxi;
    }
};
