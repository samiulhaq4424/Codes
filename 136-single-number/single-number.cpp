class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==nums[i]){
                    ++cnt;
                    if(cnt==2)
                    break;
                }
            }
            if(cnt==1)
            return nums[i];
        }
        return 0;
    }
};