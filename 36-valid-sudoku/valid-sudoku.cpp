class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9] = {0};
        int c[9] = {0};
        int b[9] = {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = 1 << (board[i][j] - '1');
                    int idx = (i / 3) * 3 + j / 3;
                    
                    if ((r[i] & v) || (c[j] & v) || (b[idx] & v)) {
                        return false;
                    }
                    
                    r[i] |= v;
                    c[j] |= v;
                    b[idx] |= v;
                }
            }
        }
        
        return true;
    }
};