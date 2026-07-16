class Solution {
public:
    bool dfs(vector<vector<char>>& grid, string& word, int idx, int r, int c, int m, int n) {
        if (idx == word.length()) return true;
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != word[idx]) return false;

        char temp = grid[r][c];
        grid[r][c] = '#';

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            if (dfs(grid, word, idx + 1, r + dirs[i][0], c + dirs[i][1], m, n)) {
                return true;
            }
        }

        grid[r][c] = temp;
        return false;
    }

    public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j, m, n)) {
                    return true;
                }
            }
        }

        return false;
    }
};