class Solution {
public:
    void helper(int ind, int n, string& temp, string& digits, vector<string>& keypad,
                vector<string>& ans) {
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        int indxKeypad = digits[ind]-'0';
        string s = keypad[indxKeypad];
        for(int i=0; i<s.size(); i++) {
            temp.push_back(s[i]);
            helper(ind+1, n, temp, digits, keypad, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans;
        string temp = "";
        int n = digits.size();
        if(n==0){
            return ans;
        }
        helper(0, n, temp, digits, keypad, ans);
        return ans;
    }
};