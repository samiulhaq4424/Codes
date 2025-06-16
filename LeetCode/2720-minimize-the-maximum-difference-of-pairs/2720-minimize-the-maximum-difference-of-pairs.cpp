class Solution {
public:
    int minimizeMax(vector<int>& values, int targetPairs) {
        if (targetPairs == 0) return 0;
        sort(values.begin(), values.end());
        int size = values.size();
        int low = 0, high = values[size - 1] - values[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 1; i < size; i++) {
                if (values[i] - values[i - 1] <= mid) {
                    count++;
                    i++;
                }
            }
            if (count >= targetPairs) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};