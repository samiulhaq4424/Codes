class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long mx = 1;
        for (int i = 0; i < n; i++) mx *= 10;
        long long hi = mx - 1;
        long long lo = mx / 10;

        for (long long i = hi; i >= lo; i--) {
            long long p = i;
            long long t = i;
            while (t > 0) {
                p = p * 10 + (t % 10);
                t /= 10;
            }

            for (long long j = hi; j * j >= p; j--) {
                if (p % j == 0) {
                    return p % 1337;
                }
            }
        }

        return 0;
    }
};