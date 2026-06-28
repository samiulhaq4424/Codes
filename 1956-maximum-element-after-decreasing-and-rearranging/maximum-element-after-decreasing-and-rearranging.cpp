class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int limit = 1;
        for (size_t idx = 1; idx < arr.size(); ++idx) {
            if (arr[idx] > limit) {
                limit += 1;
            }
        }
        return limit;
    }
};