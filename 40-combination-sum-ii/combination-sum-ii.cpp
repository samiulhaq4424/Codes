class Solution {
public:
    void helper(int ind, int n, int target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &ans) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        

        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            helper(i+1,n,target-candidates[i],temp,candidates,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        helper(0,n,target,temp,candidates,ans);
        return ans;
    }
};