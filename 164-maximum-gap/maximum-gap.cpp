class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> minBucket(bucketCount, INT_MAX);
        vector<int> maxBucket(bucketCount, INT_MIN);

        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            minBucket[idx] = min(minBucket[idx], num);
            maxBucket[idx] = max(maxBucket[idx], num);
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; ++i) {
            if (minBucket[i] == INT_MAX) continue;
            maxGap = max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};