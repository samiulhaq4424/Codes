// class Solution {
// private:
//     int exploreAndCount(vector<vector<int>>& matrix, int row, int col) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         if (row < 0 || row >= rows || col < 0 || col >= cols || matrix[row][col] != 1) {
//             return 0;
//         }
//         matrix[row][col] = 2; 
//         int count = 1;
//         count += exploreAndCount(matrix, row + 1, col);
//         count += exploreAndCount(matrix, row - 1, col);
//         count += exploreAndCount(matrix, row, col + 1);
//         count += exploreAndCount(matrix, row, col - 1);
//         return count;
//     }

//     bool isTopConnected(vector<vector<int>>& matrix, int row, int col) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         return row == 0 ||
//                (row > 0 && matrix[row - 1][col] == 2) ||
//                (row < rows - 1 && matrix[row + 1][col] == 2) ||
//                (col > 0 && matrix[row][col - 1] == 2) ||
//                (col < cols - 1 && matrix[row][col + 1] == 2);
//     }

// public:
//     vector<int> hitBricks(vector<vector<int>>& matrix, vector<vector<int>>& impacts) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         int numImpacts = impacts.size();

//         for (int i = 0; i < numImpacts; i++) {
//             int r = impacts[i][0], c = impacts[i][1];
//             matrix[r][c] = (matrix[r][c] == 0) ? -1 : 0;
//         }

//         for (int c = 0; c < cols; c++) {
//             if (matrix[0][c] == 1) {
//                 exploreAndCount(matrix, 0, c);
//             }
//         }

//         vector<int> result(numImpacts, 0);
//         for (int i = numImpacts - 1; i >= 0; i--) {
//             int r = impacts[i][0], c = impacts[i][1];
//             if (matrix[r][c] != -1) {
//                 matrix[r][c] = 1;
//                 if (isTopConnected(matrix, r, c)) {
//                     result[i] = exploreAndCount(matrix, r, c) - 1;
//                 }
//             }
//         }

//         return result;
//     }
// };



class Solution {
public:
    int exploreAndMark(vector<vector<int>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (row < 0 || col < 0 || col >= cols || row >= rows || board[row][col] != 1) {
            return 0;
        }
        
        board[row][col] = 2;
        int stableCount = 1;
        
        stableCount += exploreAndMark(board, row + 1, col);
        stableCount += exploreAndMark(board, row, col + 1);
        stableCount += exploreAndMark(board, row, col - 1);
        stableCount += exploreAndMark(board, row - 1, col);
        
        return stableCount;
    }
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numHits = hits.size();
        
        for (int idx = 0; idx < numHits; idx++) {
            int targetRow = hits[idx][0];
            int targetCol = hits[idx][1];
            if (grid[targetRow][targetCol] == 1) {
                grid[targetRow][targetCol] = -1; // Mark as removed
            } else {
                grid[targetRow][targetCol] = 0; // Was already empty
            }
        }
        
        for (int col = 0; col < cols; col++) {
            if (grid[0][col] == 1) {
                exploreAndMark(grid, 0, col);
            }
        }
        
        vector<int> result(numHits, 0);
        
        for (int idx = numHits - 1; idx >= 0; idx--) {
            int restoreRow = hits[idx][0];
            int restoreCol = hits[idx][1];
            
            if (grid[restoreRow][restoreCol] != -1) {
                continue; // This position was originally empty
            }
            
            grid[restoreRow][restoreCol] = 1;
            
            if (hasStableConnection(grid, restoreRow, restoreCol)) {
                result[idx] = exploreAndMark(grid, restoreRow, restoreCol) - 1;
            }
        }
        
        return result;
    }
    
private:
    bool hasStableConnection(vector<vector<int>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (row == 0) return true;
        
        return (row > 0 && board[row - 1][col] == 2) ||
               (col > 0 && board[row][col - 1] == 2) ||
               (row < rows - 1 && board[row + 1][col] == 2) ||
               (col < cols - 1 && board[row][col + 1] == 2);
    }
};