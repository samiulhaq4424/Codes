class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        if (p < 0) {
            x = 1.0 / x;
            p = -p;
        }
        
        double ans = 1.0;
        double curr = x;
        
        while (p > 0) {
            if (p & 1) {
                ans *= curr;
            }
            curr *= curr;
            p >>= 1;
        }
        
        return ans;
    }
};