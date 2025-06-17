class Solution {
private:
    vector<vector<int>> memo;

public:
    int strangePrinter(string input) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int len = input.size();
        memo.resize(len, vector<int>(len, 0));

        for (int start = len - 1; start >= 0; start--) {
            for (int end = start; end < len; end++) {
                int minTurns = 1 + (start + 1 <= end ? memo[start + 1][end] : 0);
                for (int split = start + 1; split <= end; split++) {
                    if (input[start] == input[split]) {
                        int left = start < split ? memo[start][split - 1] : 0;
                        int right = split + 1 <= end ? memo[split + 1][end] : 0;
                        minTurns = min(minTurns, left + right);
                    }
                }
                memo[start][end] = minTurns;
            }
        }
        return memo[0][len - 1];
    }
};