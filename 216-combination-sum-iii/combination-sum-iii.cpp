class Solution {
public:
    void helper(int ind, int sum, int k, int n, vector<int>& temp,
                vector<vector<int>>& ans) {
        if (temp.size() == k) {
            if(sum==n){
                ans.push_back(temp);
            }
            return;
        }

        for (int i = ind; i <= 9; i++) {
            if (temp.size() > k) {
                break;
            }
            if (temp.size() <= k) {
                sum = sum + i;
                temp.push_back(i);
                helper(i+1, sum, k, n, temp, ans);
                sum = sum - i;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1, 0, k, n, temp, ans);
        return ans;
    }
};