class Solution {
    void backtrack(string& s, int idx, int dots, string current, vector<string>& ans) {
        if (dots == 4) {
            if (idx == s.length()) {
                current.pop_back();
                ans.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.length()) break;

            string part = s.substr(idx, len);
            if ((part[0] == '0' && len > 1) || stoi(part) > 255) break;

            backtrack(s, idx + len, dots + 1, current + part + ".", ans);
        }
    }

    public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.length() < 4 || s.length() > 12) return ans;
        backtrack(s, 0, 0, "", ans);
        return ans;
    }
};