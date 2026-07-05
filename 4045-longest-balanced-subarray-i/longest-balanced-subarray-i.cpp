class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinct_evens;
            unordered_set<int> distinct_odds;
            
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    distinct_evens.insert(nums[j]);
                } else {
                    distinct_odds.insert(nums[j]);
                }
                
                if (distinct_evens.size() == distinct_odds.size()) {
                    int len = j - i + 1;
                    if (len > max_len) {
                        max_len = len;
                    }
                }
            }
        }
        return max_len;
    }
};