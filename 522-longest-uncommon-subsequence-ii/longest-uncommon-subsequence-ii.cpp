class Solution {
    bool isSubsequence(const string& a, const string& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for (int i = 0; i < strs.size(); ++i) {
            bool isSub = false;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isSub = true;
                    break;
                }
            }
            if (!isSub) {
                maxLen = max(maxLen, (int)strs[i].length());
            }
        }
        return maxLen;
    }
};