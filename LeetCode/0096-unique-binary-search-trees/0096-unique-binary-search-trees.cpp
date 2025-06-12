class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int k = 1; k <= n; ++k) {
            int result = 0;
            for (int i = 0; i < k; ++i) {
                result += dp[i] * dp[k - 1 - i];
            }
            dp[k] = result;
        }
        return dp[n];
    }
};