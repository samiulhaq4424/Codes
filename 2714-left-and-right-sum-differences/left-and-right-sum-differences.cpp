class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int right_sum = 0;
        for (int num : nums) {
            right_sum += num;
        }

        int left_sum = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            right_sum -= nums[i];
            ans[i] = abs(left_sum - right_sum);
            left_sum += nums[i];
        }

        return ans;
    }
};