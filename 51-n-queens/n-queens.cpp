class Solution {
public:
    void helper(int col, int n, vector<string>& board, vector<int>& leftRow,
                vector<int>& lowerDiagonal, vector<int>& upperDiagonal,
                vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[col + row] == 0 &&
                upperDiagonal[(n - 1) + col - row] == 0) {
                leftRow[row] = 1;
                lowerDiagonal[col + row] = 1;
                upperDiagonal[(n - 1) + col - row] = 1;
                board[row][col] = 'Q';
                helper(col + 1, n, board, leftRow, lowerDiagonal,
                       upperDiagonal, ans);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[col + row] = 0;
                upperDiagonal[(n - 1) + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string str(n, '.');
        for (int i = 0; i < n; i++) {
            board.push_back(str);
        }
        vector<int> leftRow(n + 1, 0);
        vector<int> lowerDiagonal(2 * n + 1, 0);
        vector<int> upperDiagonal(2 * n + 1, 0);
        helper(0, n, board, leftRow, lowerDiagonal, upperDiagonal, ans);
        return ans;
    }
};