class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> startWithIndex;
        for (int i = 0; i < n; ++i) {
            startWithIndex.emplace_back(intervals[i][0], i);
        }
        sort(startWithIndex.begin(), startWithIndex.end());
        
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            int end = intervals[i][1];
            int left = 0, right = n - 1, ans = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (startWithIndex[mid].first >= end) {
                    ans = startWithIndex[mid].second;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            result[i] = ans;
        }
        
        return result;
    }
};