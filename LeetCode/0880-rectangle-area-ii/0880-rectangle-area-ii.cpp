class Solution {
public:
    int rectangleArea(vector<vector<int>>& rects) {
        sort(rects.begin(), rects.end());
        set<long> y_coords;
        for (auto& r : rects) {
            y_coords.insert(r[1]);
            y_coords.insert(r[3]);
        }
        long result = 0, modulo = 1e9 + 7;
        long last_y = 0;
        long x_span = 0;
        for (int y : y_coords) {
            (result += x_span * (y - last_y)) %= modulo;
            x_span = 0;
            vector<int> active = {0, 0};
            for (auto& r : rects) {
                if (r[1] > y || r[3] <= y) continue;
                if (active[1] < r[0]) {
                    x_span += (r[2] - r[0]);
                    active = {r[0], r[2]};
                } else if (active[1] < r[2]) {
                    x_span += (r[2] - active[1]);
                    active[1] = r[2];
                }
            }
            last_y = y;
        }
        return result;
    }
};