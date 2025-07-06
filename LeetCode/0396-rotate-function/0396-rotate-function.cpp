class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            curr += i * nums[i];
        }
        
        long maxVal = curr;
        for (int i = 1; i < n; i++) {
            curr = curr + sum - n * nums[n - i];
            maxVal = max(maxVal, curr);
        }
        
        return maxVal;
    }
};