class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        if (left == -1) {
            return {-1, -1};
        }
        int right = findBound(nums, target, false);
        return {left, right};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int l = 0;
        int r = nums.size() - 1;
        int bound = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return bound;
    }
};