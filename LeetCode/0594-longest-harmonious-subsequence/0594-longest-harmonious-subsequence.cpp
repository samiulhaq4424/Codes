class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxLength = 0;

        for (int num : nums) {
            count[num]++;
        }

        for (auto& pair : count) {
            int currNum = pair.first;
            if (count.count(currNum + 1)) {
                maxLength = max(maxLength, pair.second + count[currNum + 1]);
            }
        }

        return maxLength;
    }
};