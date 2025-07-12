class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;
        
        int gcd_val = gcd(x, y);
        if (gcd_val == 0) return target == 0;
        
        return target % gcd_val == 0;
    }
    
private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};