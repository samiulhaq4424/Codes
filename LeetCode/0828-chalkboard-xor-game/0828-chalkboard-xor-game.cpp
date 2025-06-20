
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        
        if (totalXor == 0) {
            return true;
        }
        
        return nums.size() % 2 == 0;
    }
};