class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;
        
        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific, INT_MIN);
            dfs(i, n-1, heights, atlantic, INT_MIN);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific, INT_MIN);
            dfs(m-1, j, heights, atlantic, INT_MIN);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited, int prevHeight) {
        int m = heights.size(), n = heights[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        
        visited[i][j] = true;
        dfs(i+1, j, heights, visited, heights[i][j]);
        dfs(i-1, j, heights, visited, heights[i][j]);
        dfs(i, j+1, heights, visited, heights[i][j]);
        dfs(i, j-1, heights, visited, heights[i][j]);
    }
};