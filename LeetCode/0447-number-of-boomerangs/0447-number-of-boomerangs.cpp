class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<long long, int> distMap;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    long long dx = points[i][0] - points[j][0];
                    long long dy = points[i][1] - points[j][1];
                    long long dist = dx * dx + dy * dy;
                    distMap[dist]++;
                }
            }
            for (auto& pair : distMap) {
                int freq = pair.second;
                if (freq > 1) {
                    count += freq * (freq - 1);
                }
            }
        }
        return count;
    }
};