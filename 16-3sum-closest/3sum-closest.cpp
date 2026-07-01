class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int a = i + 1;
            int b = n - 1;
            
            while (a < b) {
                int s = nums[i] + nums[a] + nums[b];
                if (s == target) return s;
                
                if (abs(s - target) < abs(ans - target)) {
                    ans = s;
                }
                
                if (s < target) {
                    a++;
                } else {
                    b--;
                }
            }
        }
        
        return ans;
    }
};