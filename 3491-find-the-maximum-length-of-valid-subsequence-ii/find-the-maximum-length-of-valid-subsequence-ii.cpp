class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < i; j++) {
                int mod = (nums[i] + nums[j]) % k;
                if (dp[j].count(mod)) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                } else {
                    dp[i][mod] = max(dp[i][mod], 2);
                }
            }
            for (auto& [mod, len] : dp[i]) {
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};
