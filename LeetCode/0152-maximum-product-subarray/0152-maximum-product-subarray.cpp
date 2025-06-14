class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxpro = nums[0];
        int currMax = nums[0], currMin = nums[0];
        for (int i = 1; i < n; ++i) {
            int temp = currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], temp * nums[i], currMin * nums[i]});
            maxpro = max(maxpro, currMax);
        }
        return maxpro;
    }
};