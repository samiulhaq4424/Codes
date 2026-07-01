class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int a = i + 1;
            int b = n - 1;
            
            while (a < b) {
                int s = nums[i] + nums[a] + nums[b];
                if (s == 0) {
                    r.push_back({nums[i], nums[a], nums[b]});
                    while (a < b && nums[a] == nums[a + 1]) a++;
                    while (a < b && nums[b] == nums[b - 1]) b--;
                    a++;
                    b--;
                } else if (s < 0) {
                    a++;
                } else {
                    b--;
                }
            }
        }
        
        return r;
    }
};