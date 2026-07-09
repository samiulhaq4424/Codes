class Solution {
public:
    void backtrack(string& s, int idx, vector<string>& ans) {
        if (idx == s.length()) {
            ans.push_back(s);
            return;
        }

        char original = s[idx];

        backtrack(s, idx + 1, ans);

        if (isalpha(original)) {
            if (islower(original)) {
                s[idx] = toupper(original);
            } else {
                s[idx] = tolower(original);
            }

            backtrack(s, idx + 1, ans);

            s[idx] = original;
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s, 0, ans);
        return ans;
    }
};