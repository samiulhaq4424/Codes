class Solution {
public:
    int maxAdjacentDistance(vector<int>& values) {
        int size = values.size();
        int maxDiff = abs(values[size - 1] - values[0]);

        for (int i = 0; i < size - 1; i++) {
            maxDiff = max(maxDiff, abs(values[i] - values[i + 1]));
        }

        return maxDiff;
    }
};