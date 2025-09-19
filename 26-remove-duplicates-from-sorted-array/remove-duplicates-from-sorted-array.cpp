class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int indx = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[indx]!=nums[i]) {
                nums[++indx]=nums[i];
            }
        }
        return indx+1;
    }
};