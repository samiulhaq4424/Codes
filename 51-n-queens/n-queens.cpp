class Solution {
    public:
    vector<vector<string>> ans;
    int n;

    void solve(int row, int col_mask, int diag1_mask, int diag2_mask, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        int safe_spots = ((1 << n) - 1) & ~(col_mask | diag1_mask | diag2_mask);
        while (safe_spots > 0) {
            int p = safe_spots & -safe_spots;
            safe_spots -= p;
            
            int c = __builtin_ctz(p);
            board[row][c] = 'Q';
            
            solve(row + 1, col_mask | p, (diag1_mask | p) << 1, (diag2_mask | p) >> 1, board);
            
            board[row][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int num) {
        n = num;
        ans.clear();
        vector<string> board(n, string(n, '.'));
        solve(0, 0, 0, 0, board);
        return ans;
    }
};