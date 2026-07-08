class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int r = M.size();
        int c = M[0].size();
        bool f = false;

        for (int i = 0; i < r; i++) {
            if (M[i][0] == 0) f = true;
            for (int j = 1; j < c; j++) {
                if (M[i][j] == 0) {
                    M[i][0] = 0;
                    M[0][j] = 0;
                }
            }
        }

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 1; j--) {
                if (M[i][0] == 0 || M[0][j] == 0) {
                    M[i][j] = 0;
                }
            }
            if (f) M[i][0] = 0;
        }
    }
};