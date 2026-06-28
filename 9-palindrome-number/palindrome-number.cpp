class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;
        
        int a = 0;
        int b = x;
        
        while (b > a) {
            a = a * 10 + b % 10;
            b = b / 10;
        }
        
        return b == a || b == a / 10;
    }
};