class Solution {
public:
    bool isPossible(int i, int j, int n, char ch, vector<vector<char>>& board) {
        for (int k = 0; k < n; k++) {
            if (board[i][k] == ch) {
                return false;
            }
            if (board[k][j] == ch) {
                return false;
            }
            if (board[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == ch) {
                return false;
            }
        }
        return true;
    }

    bool helper(int n, vector<vector<char>>& board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isPossible(i, j, n, ch, board) == true) {
                            board[i][j] = ch;
                            if (helper(n, board) == true) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        helper(n, board);
    }
};