class Solution {
public:
    void helper(int ind, int n, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        helper(ind+1, n, nums, temp, ans);
        temp.pop_back();

        helper(ind+1, n, nums, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // unordered_set<vector<int>> st;
        // int n=nums.size();
        // helper(0,n,st,nums);
        // for(auto it:)
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        helper(0, n, nums, temp, ans);
        return ans;
    }
};