class Solution {
public:
    int cache[10][10][2];

    int countOnes(int pos, int ones, string& num, bool isConstrained) {
        if (pos >= num.size()) return ones;
        if (cache[pos][ones][isConstrained] != -1) return cache[pos][ones][isConstrained];

        int total = 0;
        int maxDigit = isConstrained ? num[pos] - '0' : 9;
        for (int d = 0; d <= maxDigit; d++) {
            total += countOnes(pos + 1, ones + (d == 1), num, isConstrained && d == maxDigit);
        }
        return cache[pos][ones][isConstrained] = total;
    }

    int countDigitOne(int n) {
        fill(&cache[0][0][0], &cache[0][0][0] + 10 * 10 * 2, -1);
        string numStr = to_string(n);
        return countOnes(0, 0, numStr, true);
    }
};