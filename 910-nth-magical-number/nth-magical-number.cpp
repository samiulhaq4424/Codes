class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long gcd = __gcd(a, b);
        long long lcm = (a * 1LL * b) / gcd;
        long long left = min(a, b), right = n * 1LL * min(a, b);
        long long result = 0, mod = 1e9 + 7;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = mid / a + mid / b - mid / lcm;
            if (count < n) {
                left = mid + 1;
            } else {
                result = mid % mod;
                right = mid - 1;
            }
        }
        return result;
    }
};