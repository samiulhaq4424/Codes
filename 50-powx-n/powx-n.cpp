class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long y = n;
        if(n<0){
            y= -1 * y;
        }
        while(y>0){
            if(y%2 == 1){
                ans = ans*x;
                y=y-1;
            } else if(y%2 == 0){
                x=x*x;
                y=y/2;
            }
        }
        if(n<0) {
            return 1.0 / ans;
        }
        return ans;
    }
};