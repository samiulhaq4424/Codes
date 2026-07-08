class Solution {
public:
    vector<int> intersection(vector<int>& N1, vector<int>& N2) {
        unordered_set<int> S(N1.begin(), N1.end());
        vector<int> ans;

        for (size_t i = 0; i < N2.size(); i++) {
            if (S.count(N2[i])) {
                ans.push_back(N2[i]);
                S.erase(N2[i]);
            }
        }

        return ans;
    }
};