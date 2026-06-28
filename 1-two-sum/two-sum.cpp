class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapper;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int complement = target - nums[idx];
            if (mapper.count(complement)) {
                return {mapper[complement], idx};
            }
            mapper[nums[idx]] = idx;
        }
        return {};
    }
};