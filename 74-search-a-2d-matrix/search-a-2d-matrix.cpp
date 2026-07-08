class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int T) {
        int r = M.size();
        int c = M[0].size();
        int l = 0;
        int h = r * c - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            int v = M[m / c][m % c];

            if (v == T) {
                return true;
            } else if (v < T) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return false;
    }
};