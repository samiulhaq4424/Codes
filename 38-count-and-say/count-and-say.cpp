class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string result = "";
        int len = prev.length();

        for (int i = 0; i < len; i++) {
            int count = 1;
            while (i + 1 < len && prev[i] == prev[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + prev[i];
        }

        return result;
    }
};