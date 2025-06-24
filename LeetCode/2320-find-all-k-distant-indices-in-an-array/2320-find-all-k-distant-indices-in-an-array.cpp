class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndices;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            for (int keyIdx : keyIndices) {
                if (abs(i - keyIdx) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        
        return result;
    }
};