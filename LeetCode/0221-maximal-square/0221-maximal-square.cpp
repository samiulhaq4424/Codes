class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int max_area = 0;
        for (int i = 1; i <= n; ++i) {
            int prev = 0;
            for (int j = 1; j <= m; ++j) {
                int curr_side = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    curr_side = min({dp[j], dp[j - 1], prev}) + 1;
                    int curr_area = curr_side * curr_side;
                    max_area = max(max_area, curr_area);
                } else {
                    curr_side = 0;
                }
                prev = dp[j];
                dp[j] = curr_side;
            }
        }
        return max_area;
    }
};