class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = INT_MAX;
        int maxDiff = INT_MIN;
        
        for (int num : nums) {
            if (num - minSoFar > 0) {
                maxDiff = max(maxDiff, num - minSoFar);
            }
            minSoFar = min(minSoFar, num);
        }
        
        return maxDiff == INT_MIN ? -1 : maxDiff;
    }
};