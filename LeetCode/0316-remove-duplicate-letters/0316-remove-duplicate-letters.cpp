class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> seen(26, false);
        string result;
        
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (!seen[s[i] - 'a']) {
                while (!result.empty() && result.back() > s[i] && last[result.back() - 'a'] > i) {
                    seen[result.back() - 'a'] = false;
                    result.pop_back();
                }
                result.push_back(s[i]);
                seen[s[i] - 'a'] = true;
            }
        }
        
        return result;
    }
};