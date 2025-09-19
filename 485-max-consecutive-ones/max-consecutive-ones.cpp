class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxi=0;
        for(auto it : nums) {
            if(it==1){
                ++cnt;
                maxi=max(maxi,cnt);
                cout<<maxi<<endl;
            } else {
                cnt=0;
            }
                

        }
        return maxi;
    }
};