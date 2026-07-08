class Solution {
public:
    vector<vector<int>> subsets(vector<int>& N) {
        vector<vector<int>> ans;
        int sz = N.size();
        int total = 1 << sz;

        for (int i = 0; i < total; i++) {
            vector<int> cur;
            for (int j = 0; j < sz; j++) {
                if ((i >> j) & 1) {
                    cur.push_back(N[j]);
                }
            }
            ans.push_back(cur);
        }

        return ans;
    }
};