class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shiftCount = 0;

        while (k > 1) {
            int index = 63 - __builtin_clzll(k); // equivalent to log2(k)
            if ((1LL << index) == k) {
                --index;
            }
            k -= (1LL << index);
            if (operations[index] == 1) {
                ++shiftCount;
            }
        }

        return 'a' + (shiftCount % 26);
    }
};
