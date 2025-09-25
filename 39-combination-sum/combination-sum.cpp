class Solution {
public:

    void helper(vector<vector<int>> &ans, vector<int> &v, int sum, int ind, vector<int> &arr){
        if(sum<0 || ind == arr.size())
        return;
        if(sum == 0){
            ans.push_back(v);
            return;
        }

        v.push_back(arr[ind]);
        sum-=arr[ind];
        helper(ans,v,sum,ind,arr);
        v.pop_back();
        sum+=arr[ind];
        helper(ans,v,sum,ind+1,arr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum=target;
        helper(ans,v,sum,0,candidates);
        return ans;
    }
};