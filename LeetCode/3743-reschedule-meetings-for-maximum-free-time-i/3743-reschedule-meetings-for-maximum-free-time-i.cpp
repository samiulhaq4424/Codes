class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), maxGap = 0;
        vector<int> durations(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            durations[i + 1] = durations[i] + (endTime[i] - startTime[i]);
        }
        for (int i = k - 1; i < n; ++i) {
            int segmentEnd = (i == n - 1) ? eventTime : startTime[i + 1];
            int segmentStart = (i == k - 1) ? 0 : endTime[i - k];
            int occupied = durations[i + 1] - durations[i - k + 1];
            maxGap = max(maxGap, segmentEnd - segmentStart - occupied);
        }
        return maxGap;
    }
};
