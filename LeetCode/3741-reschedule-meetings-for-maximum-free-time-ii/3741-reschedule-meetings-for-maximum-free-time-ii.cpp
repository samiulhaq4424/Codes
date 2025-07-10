class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<bool> movable(n, false);
        int forwardGap = 0, backwardGap = 0;

        for (int i = 0; i < n; ++i) {
            int duration = endTime[i] - startTime[i];
            int gapBefore = (i == 0 ? startTime[i] : startTime[i] - endTime[i-1]);
            if (duration <= forwardGap) movable[i] = true;
            forwardGap = max(forwardGap, gapBefore);

            int j = n - 1 - i;
            int gapAfter = (j == n-1 ? eventTime - endTime[j] : startTime[j+1] - endTime[j]);
            if (endTime[j] - startTime[j] <= backwardGap) movable[j] = true;
            backwardGap = max(backwardGap, gapAfter);
        }

        int maxFree = 0;
        for (int i = 0; i < n; ++i) {
            int leftBound = (i == 0 ? 0 : endTime[i-1]);
            int rightBound = (i == n-1 ? eventTime : startTime[i+1]);
            if (movable[i]) {
                maxFree = max(maxFree, rightBound - leftBound);
            } else {
                maxFree = max(maxFree, rightBound - leftBound - (endTime[i] - startTime[i]));
            }
        }
        return maxFree;
    }
};