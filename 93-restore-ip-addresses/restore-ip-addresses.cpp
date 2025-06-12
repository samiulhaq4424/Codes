class Solution {
public:
    void solve(string& s, vector<string>& v, int index, vector<string>& ans) {
        int n = s.size(), m = v.size();
        if (index == n && m == 4) {
            ans.push_back(v[0] + "." + v[1] + "." + v[2] + "." + v[3]);
            return;
        }
        if (index >= n || m > 4) return;
        for (int i = 0; i < 3 && index + i < n; ++i) {
            string str = s.substr(index, i + 1);
            if (str[0] == '0' && i > 0) continue;
            int num = stoi(str);
            if (num >= 0 && num <= 255) {
                v.push_back(str);
                solve(s, v, index + i + 1, ans);
                v.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans, v;
        solve(s, v, 0, ans);
        return ans;
    }
};