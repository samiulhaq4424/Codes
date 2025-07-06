class Solution {
public:
    int lastRemaining(int n) {
        int first = 1;
        int step = 1;
        int remaining = n;
        bool leftToRight = true;
        
        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) {
                first += step;
            }
            step *= 2;
            remaining /= 2;
            leftToRight = !leftToRight;
        }
        
        return first;
    }
};