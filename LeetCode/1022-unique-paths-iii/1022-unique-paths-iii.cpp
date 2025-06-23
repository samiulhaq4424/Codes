class Solution {
public:
    int m, n, total = 0;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(int row, int col, int curr, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (grid[row][col] == 2) return curr == total ? 1 : 0;
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == -1) return 0;
        vis[row][col] = 1;
        int paths = 0;
        for (auto &d : dir) {
            int Nrow = row + d[0];
            int Ncol = col + d[1];
            if (Nrow >= 0 && Ncol >= 0 && Nrow < m && Ncol < n && !vis[Nrow][Ncol]) {
                paths += dfs(Nrow, Ncol, curr + 1, grid, vis);
            }
        }
        vis[row][col] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int sr = -1, sc = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) total++;
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(sr, sc, 1, grid, vis);
    }
};