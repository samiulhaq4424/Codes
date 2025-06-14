class Solution {
private:
    void getCombi(vector<int>& vals, int tar, int start, int k, vector<vector<int>>& ans) {
        if (tar < 0 || vals.size() > k || 9 - start + 1 < k - vals.size()) return;
        if (vals.size() == k && tar == 0) {
            ans.push_back(vals);
            return;
        }
        for (int i = start; i <= 9 && tar >= i; ++i) {
            vals.push_back(i);
            getCombi(vals, tar - i, i + 1, k, ans);
            vals.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vals;
        getCombi(vals, n, 1, k, ans);
        return ans;
    }
};