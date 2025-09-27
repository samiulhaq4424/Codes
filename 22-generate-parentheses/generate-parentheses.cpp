class Solution {
public:
    void helper(int open, int close, string &str, vector<string> &ans) {
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }

        if(open!=0){
            str.push_back('(');
            helper(open-1, close, str, ans);
            str.pop_back();
        }
        if(close>open){
            str.push_back(')');
            helper(open, close-1, str, ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        if(n<=0){
            return ans;
        }
        int open=n,close=n;
        helper(open, close, str, ans);
        return ans;
    }
};