class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rects) {
        unordered_map<string, int> pointCounts;
        for (const auto& rect : rects) {
            vector<string> points(4);
            points[0] = to_string(rect[0]) + "," + to_string(rect[1]); // Bottom-left
            points[1] = to_string(rect[2]) + "," + to_string(rect[1]); // Bottom-right
            points[2] = to_string(rect[0]) + "," + to_string(rect[3]); // Top-left
            points[3] = to_string(rect[2]) + "," + to_string(rect[3]); // Top-right
            for (int i = 0; i < 4; ++i) {
                if (pointCounts[points[i]] & (1 << i)) return false;
                pointCounts[points[i]] |= (1 << i);
            }
        }
        int singlePoints = 0;
        for (const auto& [point, count] : pointCounts) {
            if (count && !(count & (count - 1))) {
                if (++singlePoints > 4) return false;
            } else if (count != 3 && count != 5 && count != 10 && count != 12 && count != 15) {
                return false;
            }
        }
        return singlePoints == 4;
    }
};