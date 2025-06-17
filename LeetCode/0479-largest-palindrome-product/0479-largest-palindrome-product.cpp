class Solution {
public:
    int largestPalindrome(int digits) {
        if (digits == 1) return 9;
        long long upper = pow(10, digits) - 1;
        long long lower = upper / 10;

        for (long long num = upper - 1; num > lower; num--) {
            string forward = to_string(num);
            string palindrome = forward;
            reverse(palindrome.begin(), palindrome.end());
            long long product = stoll(forward + palindrome);
            
            for (long long factor = upper; factor * factor >= product; factor--) {
                if (product % factor == 0) {
                    return product % 1337;
                }
            }
        }
        return 0;
    }
};