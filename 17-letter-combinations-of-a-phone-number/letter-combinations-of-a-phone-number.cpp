class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> m = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> r = {""};
        
        for (char d : digits) {
            vector<string> t;
            string s = m[d - '0'];
            for (string x : r) {
                for (char c : s) {
                    t.push_back(x + c);
                }
            }
            r = t;
        }
        
        return r;
    }
};