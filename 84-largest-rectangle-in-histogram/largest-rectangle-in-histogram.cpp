class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> s;
        int m = 0;
        
        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
            while (!s.empty() && heights[s.back()] >= h) {
                int j = s.back();
                s.pop_back();
                int w = s.empty() ? i : (i - s.back() - 1);
                int a = heights[j] * w;
                if (a > m) {
                    m = a;
                }
            }
            s.push_back(i);
        }
        
        return m;

    }
};