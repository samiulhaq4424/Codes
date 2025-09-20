class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        long long sum =0, maxi = LLONG_MIN;
        unordered_map<int,int> mp;

        while(j<n){
            sum = sum+(long long)nums[j];
            mp[nums[j]]++;
            if(j-i+1 < k){
                ++j;
            }
            else if(j-i+1 == k) {
                if(mp.size()==k)
                    maxi = max(maxi,sum);
                sum=sum-nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                ++i;
                ++j;
            }
        }
        return maxi!=LLONG_MIN?maxi:0;
    }
};