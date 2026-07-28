class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());

        string result = half;
        if (n % 2 != 0) {
            result += s[n / 2];
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        result += rev;

        return result;
    }
};