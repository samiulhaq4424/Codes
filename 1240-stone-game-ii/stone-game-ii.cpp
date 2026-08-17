class Solution {
    int memo[101][101];

    int dfs(const vector<int>& suffixSum, int i, int M, int n) {
        if (i >= n) return 0;
        if (i + 2 * M >= n) return suffixSum[i];
        if (memo[i][M] != -1) return memo[i][M];

        int minOpponent = INT_MAX;
        for (int X = 1; X <= 2 * M; ++X) {
            minOpponent = min(minOpponent, dfs(suffixSum, i + X, max(M, X), n));
        }

        return memo[i][M] = suffixSum[i] - minOpponent;
    }

    public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        memset(memo, -1, sizeof(memo));
        return dfs(suffixSum, 0, 1, n);
    }
};