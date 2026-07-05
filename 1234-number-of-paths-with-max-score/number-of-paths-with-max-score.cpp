class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || dp[i][j] == -1) continue;
                
                int val = dp[i][j];
                int paths = cnt[i][j];
                
                int di[3] = {-1, 0, -1};
                int dj[3] = {0, -1, -1};
                
                for (int d = 0; d < 3; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    
                    if (ni >= 0 && nj >= 0 && board[ni][nj] != 'X') {
                        int nxt_val = val;
                        if (board[ni][nj] != 'E') {
                            nxt_val += board[ni][nj] - '0';
                        }
                        
                        if (nxt_val > dp[ni][nj]) {
                            dp[ni][nj] = nxt_val;
                            cnt[ni][nj] = paths;
                        } else if (nxt_val == dp[ni][nj]) {
                            cnt[ni][nj] = (cnt[ni][nj] + paths) % mod;
                        }
                    }
                }
            }
        }
        
        if (dp[0][0] == -1) return {0, 0};
        return {dp[0][0], cnt[0][0]};
    }
};