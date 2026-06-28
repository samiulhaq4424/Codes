class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int max_len = 0, start_idx = 0;
        for (int idx = 0; idx < s.length();) {
            if (s.length() - idx <= max_len / 2) break;
            int left = idx, right = idx;
            while (right < s.length() - 1 && s[right + 1] == s[right]) {
                right++;
            }
            idx = right + 1;
            while (right < s.length() - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if (right - left + 1 > max_len) {
                start_idx = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(start_idx, max_len);
    }
};