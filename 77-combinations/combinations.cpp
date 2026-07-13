class Solution {
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& ans) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, ans);
            current.pop_back();
        }
    }

    public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(1, n, k, current, ans);
        return ans;
    }
};