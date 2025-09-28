class Solution {
public:
    bool isPalin(string &str) {
        int n = str.size();
        int i=0;
        while(i<n/2){
           if(str[i] != str[n-1-i]){
                return false;
           }
           ++i;
        }
        return true;
    }

    void helper(int ind, int n, string &s, vector<string> &str, vector<vector<string>> &ans) {
        if(ind==n){
            ans.push_back(str);
            return;
        }
        for(int i=ind; i<n; i++) {
            string temp = s.substr(ind,i-ind+1);
            if(isPalin(temp) == true) {
                str.push_back(temp);
                helper(i+1, n, s, str, ans);
                str.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        int n = s.size();

        helper(0, n, s, str, ans);
        return ans;
    }
};