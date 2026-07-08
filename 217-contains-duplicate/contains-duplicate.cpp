class Solution {
public:
    bool containsDuplicate(vector<int>& N) {
        unordered_set<int> S;
        for (int i = 0; i < N.size(); i++) {
            if (S.find(N[i]) != S.end()) {
                return true;
            }
            S.insert(N[i]);
        }
        return false;
    }
};