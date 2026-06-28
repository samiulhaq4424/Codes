class Solution {
public:
        int a = 0;
    int b;

    void dfs(int r, int c, int d1, int d2) {
        if (r == b) {
            a++;
            return;
        }

        int m = ((1 << b) - 1) & ~(c | d1 | d2);
        while (m > 0) {
            int p = m & -m;
            m -= p;
            dfs(r + 1, c | p, (d1 | p) << 1, (d2 | p) >> 1);
        }
    }

    int totalNQueens(int n) {
        a = 0;
        b = n;
        dfs(0, 0, 0, 0);
        return a;
    }
};