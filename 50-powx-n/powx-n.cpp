class Solution {
public:
    double helper(double x, long long y){
        if(y==0){
            return 1;
        }
        double ans = helper(x,y/2);
        ans=ans*ans;
        if(y%2==1){
            ans=ans*x;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long y = n;
        if(n<0){
            y=-1*y;
        }
        double ans = helper(x,y);
        if(n<y){
            return 1.0/ans;
        }
        return ans;
    }
};