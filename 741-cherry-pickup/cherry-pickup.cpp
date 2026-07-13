class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for (int step = 1; step <= 2 * n - 2; ++step) {
            vector<vector<int>> next_dp(n, vector<int>(n, -1));
            for (int r1 = max(0, step - (n - 1)); r1 <= min(n - 1, step); ++r1) {
                for (int r2 = max(0, step - (n - 1)); r2 <= min(n - 1, step); ++r2) {
                    int c1 = step - r1;
                    int c2 = step - r2;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int cherries = grid[r1][c1];
                    if (r1 != r2) {
                        cherries += grid[r2][c2];
                    }

                    int max_prev = -1;
                    if (r1 > 0 && r2 > 0) max_prev = max(max_prev, dp[r1 - 1][r2 - 1]);
                    if (r1 > 0)          max_prev = max(max_prev, dp[r1 - 1][r2]);
                    if (r2 > 0)          max_prev = max(max_prev, dp[r1][r2 - 1]);
                    max_prev = max(max_prev, dp[r1][r2]);

                    if (max_prev != -1) {
                        next_dp[r1][r2] = max_prev + cherries;
                    }
                }
            }
            dp = move(next_dp);
        }

        return max(0, dp[n - 1][n - 1]);
    }
};