class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());
        int maximum = 0;
        for (int i = n - 2; i >= 0; --i) {
            maximum = max(maximum, nums[i + 1] - nums[i]);
        }
        return maximum;
    }
};