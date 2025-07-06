class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1, count = 9, start = 1;
        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        start += (n - 1) / digits;
        string num = to_string(start);
        return num[(n - 1) % digits] - '0';
    }
};