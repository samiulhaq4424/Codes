class Solution {
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, ans);
            current.pop_back();
        }
    }

    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(candidates, target, 0, current, ans);
        return ans;
    }
};