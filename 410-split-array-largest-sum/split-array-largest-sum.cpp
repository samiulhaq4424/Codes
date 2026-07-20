class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;
            int count = 1;
            long long current_sum = 0;

            for (int num : nums) {
                if (current_sum + num > mid) {
                    count++;
                    current_sum = num;
                } else {
                    current_sum += num;
                }
            }

            if (count > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};