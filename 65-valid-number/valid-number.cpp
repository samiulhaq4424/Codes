class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();

        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }

        while (i < n) {
            char c = s[i];

            if (c >= '0' && c <= '9') {
                seenDigit = true;
            } else if (c == '.') {
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false;
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) {
                    i++;
                }
            } else {
                return false;
            }
            i++;
        }

        return seenDigit;
    }
};