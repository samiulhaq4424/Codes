class Solution {
public:
    bool hasEnoughNumbers(int rows, int cols, int target, int value) {
        int count = 0;
        for (int i = 1; i <= rows; i++) {
            int contribution = min(value / i, cols);
            if (contribution == 0) break;
            count += contribution;
        }
        return count >= target;
    }

    int findKthNumber(int rows, int cols, int target) {
        int left = 1, right = rows * cols;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasEnoughNumbers(rows, cols, target, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};