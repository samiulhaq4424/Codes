class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> a;
        a.push_back(-1);
        int m = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                a.push_back(i);
            } else {
                a.pop_back();
                if (a.empty()) {
                    a.push_back(i);
                } else {
                    int l = i - a.back();
                    if (l > m) {
                        m = l;
                    }
                }
            }
        }
        
        return m;

    }
};