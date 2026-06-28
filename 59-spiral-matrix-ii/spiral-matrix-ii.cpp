class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n, 0));
        
        int b = 1;
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        
        while (r1 <= r2 && c1 <= c2) {
            for (int i = c1; i <= c2; ++i) {
                a[r1][i] = b++;
            }
            r1++;
            
            for (int i = r1; i <= r2; ++i) {
                a[i][c2] = b++;
            }
            c2--;
            
            if (r1 <= r2) {
                for (int i = c2; i >= c1; --i) {
                    a[r2][i] = b++;
                }
                r2--;
            }
            
            if (c1 <= c2) {
                for (int i = r2; i >= r1; --i) {
                    a[i][c1] = b++;
                }
                c1++;
            }
        }
        
        return a;

    }
};