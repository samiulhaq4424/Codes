class Solution {
public:
    void helper(int ind, int n, int target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &ans) {
        if(ind==n){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            helper(ind, n, target-candidates[ind], temp, candidates, ans);
            temp.pop_back();
        }
        helper(ind+1, n, target, temp, candidates, ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        helper(0,n,target,temp,candidates,ans);
        return ans;
    }
};