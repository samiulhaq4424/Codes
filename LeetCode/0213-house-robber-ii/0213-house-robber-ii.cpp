class Solution {
public:
    private:
    int linearRob(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        vector<int> dp(end - start + 3, 0);
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= end - start + 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + (i - 1 + start < nums.size() ? nums[i - 1 + start] : 0));
        }
        return dp[end - start + 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int one = linearRob(nums, 0, n - 2);
        int two = linearRob(nums, 1, n - 1);
        return max(one, two);
    }
};