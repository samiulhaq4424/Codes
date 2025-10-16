class DisjointSet {
private:
    vector<int> parent, size;

public:
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
        if(ulp_u == ulp_v){
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
    int removeStones(vector<vector<int>>& stones) {
        int numOfStones = stones.size();
        int maxRow = INT_MIN;
        int maxColumn = INT_MIN;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxColumn = max(maxColumn, it[1]);
        }

        DisjointSet ds(maxRow + maxColumn + 2);
        unordered_map<int, int> mp;
        for (auto it : stones) {
            int row = it[0];
            int column = maxRow + 1 + it[1];
            ds.unionBySize(row, column);
            mp[row] = 1;
            mp[column] = 1;
        }

        int numOfComp = 0;
        for (auto it : mp) {
            if (ds.findParent(it.first) == it.first) {
                ++numOfComp;
            }
        }
        return numOfStones - numOfComp;
    }
};