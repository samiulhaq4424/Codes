class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int size = nums.size();
        vector<long long> prefixMax(size), suffixMin(size);

        prefixMax[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], static_cast<long long>(nums[i]));
        }
        suffixMin[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], static_cast<long long>(nums[i]));
        }

        int chunks = 0;
        for (int i = 0; i < size; ++i) {
            long long maxBefore = (i > 0 ? prefixMax[i - 1] : LLONG_MIN);
            long long minAfter = suffixMin[i];

            if (maxBefore <= minAfter) {
                chunks++;
            }
        }
        return chunks;
    }
};