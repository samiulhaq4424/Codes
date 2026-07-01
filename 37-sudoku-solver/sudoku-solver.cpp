class Solution {
public:
    int r[9] = {0};
    int c[9] = {0};
    int b[9] = {0};

    bool dfs(vector<vector<char>>& g, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return dfs(g, i + 1, 0);
        if (g[i][j] != '.') return dfs(g, i, j + 1);

        int idx = (i / 3) * 3 + j / 3;
        int m = ~(r[i] | c[j] | b[idx]) & 0x1FF;

        while (m > 0) {
            int ls = m & -m;
            m -= ls;
            int num = __builtin_ctz(ls);

            g[i][j] = '1' + num;
            r[i] |= ls;
            c[j] |= ls;
            b[idx] |= ls;

            if (dfs(g, i, j + 1)) return true;

            g[i][j] = '.';
            r[i] &= ~ls;
            c[j] &= ~ls;
            b[idx] &= ~ls;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = 1 << (board[i][j] - '1');
                    int idx = (i / 3) * 3 + j / 3;
                    r[i] |= v;
                    c[j] |= v;
                    b[idx] |= v;
                }
            }
        }
        dfs(board, 0, 0);
    }
};