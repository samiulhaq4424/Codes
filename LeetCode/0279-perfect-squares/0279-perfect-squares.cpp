class Solution {
public:
    int numSquares(int n) {
        int root = static_cast<int>(sqrt(n));
        if (root * root == n) return 1;
        vector<int> allSqrs;
        for (int i = 1; i <= root; ++i) {
            allSqrs.push_back(i * i);
        }
        vector<int> memo(n + 1, n + 1);
        queue<int> q;
        q.push(n);
        memo[n] = 0;
        int minCount = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            minCount = memo[curr] + 1;
            for (int sqr : allSqrs) {
                int next = curr - sqr;
                if (next < 0) break;
                if (next == 0) return minCount;
                if (memo[next] == n + 1) {
                    memo[next] = minCount;
                    q.push(next);
                }
            }
        }
        return minCount;
    }
};