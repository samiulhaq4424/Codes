class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue < pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == n - 1 && y == m - 1) {
                return dis;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int maxEffort = max(dis, abs(heights[nx][ny] - heights[x][y]));
                    if (maxEffort < dist[nx][ny]) {
                        dist[nx][ny] = maxEffort;
                        pq.push({maxEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};