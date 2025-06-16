class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    heap.emplace(grid[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int totalWater = 0;
        
        while (!heap.empty()) {
            auto [height, row, col] = heap.top();
            heap.pop();
            
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    totalWater += max(0, height - grid[newRow][newCol]);
                    heap.emplace(max(height, grid[newRow][newCol]), newRow, newCol);
                }
            }
        }
        
        return totalWater;
    }
};