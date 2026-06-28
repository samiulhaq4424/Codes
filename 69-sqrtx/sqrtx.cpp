class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        int a = 1;
        int b = x / 2;
        int r = 0;
        
        while (a <= b) {
            int c = a + (b - a) / 2;
            if (c <= x / c) {
                r = c;
                a = c + 1;
            } else {
                b = c - 1;
            }
        }
        
        return r;

    }
};