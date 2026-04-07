class Solution {
    int count = 0;
    
    void dfs(int pos, int n, int mask) {
        if (pos == 0) {
            count++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!(mask & (1 << i))) {
                if (i % pos == 0 || pos % i == 0) {
                    dfs(pos - 1, n, mask | (1 << i));
                }
            }
        }
    }
    
public:
    int countArrangement(int n) {
        dfs(n, n, 0);
        return count;
    }
};