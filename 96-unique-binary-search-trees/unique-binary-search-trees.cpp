class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int count[100] = {0};
        count[0] = 1;
        count[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                count[i] = count[i] + (count[j - 1] * count[i - j]);
            }
        }
        return count[n];
    }
};