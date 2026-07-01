class Solution {
public:
    public:
    vector<vector<int>> ans;
    void backtrack(vector<int> nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[idx]) continue;
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};