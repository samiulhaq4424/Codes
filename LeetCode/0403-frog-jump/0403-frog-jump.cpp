class Solution {
public:
    bool canCross(vector<int>& positions) {
        int n = positions.size();
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        reachable[0][1] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int jump = positions[i] - positions[j];
                if (jump > 0 && jump < n && reachable[j][jump]) {
                    if (i == n - 1) return true;
                    reachable[i][jump] = true;
                    if (jump + 1 < n) reachable[i][jump + 1] = true;
                    if (jump - 1 >= 0) reachable[i][jump - 1] = true;
                }
            }
        }

        return false;
    }
};