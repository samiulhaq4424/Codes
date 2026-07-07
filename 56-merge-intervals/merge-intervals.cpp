class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[i][0] > intervals[j][0]) {
                    swap(intervals[i], intervals[j]);
                }
            }
        }

        vector<vector<int>> consolidatedSegments;
        consolidatedSegments.push_back(intervals[0]);

        for (int index = 1; index < intervals.size(); index++) {
            vector<int>& activeSegment = consolidatedSegments.back();
            vector<int>& targetSegment = intervals[index];

            if (targetSegment[0] <= activeSegment[1]) {
                if (targetSegment[1] > activeSegment[1]) {
                    activeSegment[1] = targetSegment[1];
                }
            } else {
                consolidatedSegments.push_back(targetSegment);
            }
        }

        return consolidatedSegments;
    }
};