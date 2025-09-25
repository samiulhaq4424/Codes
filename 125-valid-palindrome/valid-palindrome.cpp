class Solution {
public:
    bool helper(int ind, int n, string& s) {
        if (ind >= n / 2) {
            return true;
        }

        if (s[ind] != s[n - 1 - ind]) {
            return false;
        }

        return helper(ind + 1, n, s);
    }
    bool isPalindrome(string s) {
        // if (s.size() <= 1) {
        //     return true;
        // }
        string str = "";
        for (auto it : s) {
            if (it >= 'a' && it <= 'z')
                str += it;
            if(it >= '0' && it <= '9')
                str+=it;
            if (it >= 'A' && it <= 'Z')
                str += (char)('a' + (it - 'A'));
        }

        int n = str.size();
        cout << str << endl;
        return helper(0, n, str);
    }
};