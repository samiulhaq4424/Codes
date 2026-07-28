class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hexDigits = "0123456789abcdef";
        string result = "";
        unsigned int n = num;

        while (n > 0) {
            result += hexDigits[n & 0xF];
            n >>= 4;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};