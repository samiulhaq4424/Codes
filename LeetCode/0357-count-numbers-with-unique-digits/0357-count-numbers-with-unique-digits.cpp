class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n > 10) n = 10;
        
        int ans = 9;
        int available = 9;
        
        for (int i = 0; i < n - 1; i++) {
            ans *= available;
            available--;
        }
        
        return ans + countNumbersWithUniqueDigits(n - 1);
    }
};