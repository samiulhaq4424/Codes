class Solution {
public:
    public:
    vector<vector<int>> r;
    vector<int> t;

    void dfs(vector<int>& c, int tgt, int idx) {
        if (tgt == 0) {
            r.push_back(t);
            return;
        }
        for (int i = idx; i < c.size(); ++i) {
            if (c[i] <= tgt) {
                t.push_back(c[i]);
                dfs(c, tgt - c[i], i);
                t.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        r.clear();
        t.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return r;
    }

};