class Solution {
public:
    int findRotateSteps(string ring, string key) {
       int n = ring.size();
       int m = key.size();

       vector<vector<int>> pos(26);
       for (int i = 0; i < n; i++) {
        pos[ring[i] - 'a'].push_back(i);
       }

       vector<int> dp(n, 0);

       for (int i = m - 1; i >= 0; i--) {
        vector<int> next_dp(n, INT_MAX);
        int target = key[i] - 'a';

        for (int ring_pos = 0; ring_pos < n; ring_pos++) {
            for (int next_pos : pos[target]) {
                int dist = abs(ring_pos - next_pos);
                int step = min(dist, n - dist);
                next_dp[ring_pos] = min(next_dp[ring_pos], step + 1 + dp[next_pos]);
            }
        }
        dp = next_dp;
       }

       return dp[0];
    }
};