class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (int freq : count) {
            length += (freq / 2) * 2;
            if (freq % 2 != 0) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};