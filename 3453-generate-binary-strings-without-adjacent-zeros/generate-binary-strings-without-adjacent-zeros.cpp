class Solution {
public:
    void helper(int ind, int n, string &str, vector<string> &ans) {
        if(ind == n){
            ans.push_back(str);
            return;
        }

        if(ind==0 || (ind>0 && str[ind-1]!='0')){
            str.push_back('0');
            helper(ind+1,n,str,ans);
            str.pop_back();
        }
        if(ind>=0){
            str.push_back('1');
            helper(ind+1,n,str,ans);
            str.pop_back();
        }

    }
    vector<string> validStrings(int n) {
        string str="";
        vector<string> ans;
        helper(0,n,str,ans);
        return ans;
    }
};