class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndex;
        sumIndex[0] = -1;
        int maxLen = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);
            
            if (sumIndex.count(sum)) {
                maxLen = max(maxLen, i - sumIndex[sum]);
            } else {
                sumIndex[sum] = i;
            }
        }
        
        return maxLen;
    }
};