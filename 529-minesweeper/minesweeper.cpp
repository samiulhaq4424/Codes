class Solution {
    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') return;

        int mines = 0;
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                mines++;
            }
        }

        if (mines > 0) {
            board[r][c] = '0' + mines;
        } else {
            board[r][c] = 'B';
            for (auto& d : dirs) {
                dfs(board, r + d[0], c + d[1], m, n);
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        int m = board.size();
        int n = board[0].size();
        dfs(board, r, c, m, n);
        
        return board;
    }
};