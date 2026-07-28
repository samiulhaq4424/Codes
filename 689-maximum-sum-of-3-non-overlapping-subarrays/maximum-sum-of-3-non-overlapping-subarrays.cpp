class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        auto getSum = [&](int i) {
            return sum[i + k] - sum[i];
        };

        int m = n - k + 1;
        vector<int> left(m, 0);
        int bestLeft = 0;
        for (int i = 0; i < m; ++i) {
            if (getSum(i) > getSum(bestLeft)) {
                bestLeft = i;
            }
            left[i] = bestLeft;
        }

        vector<int> right(m, 0);
        int bestRight = m - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (getSum(i) >= getSum(bestRight)) {
                bestRight = i;
            }
            right[i] = bestRight;
        }

        vector<int> result(3, -1);
        int maxSum = 0;

        for (int j = k; j <= n - 2 * k; ++j) {
            int l = left[j - k];
            int r = right[j + k];
            int currentSum = getSum(l) + getSum(j) + getSum(r);

            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = {l, j, r};
            }
        }

        return result;
    }
};