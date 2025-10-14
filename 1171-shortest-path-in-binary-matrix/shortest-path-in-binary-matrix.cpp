class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        grid[nx][ny] == 0) {
                        if (dis + 1 < dist[nx][ny]) {
                            dist[nx][ny] = dis + 1;
                            // if (nx == n - 1 && ny == n - 1) {
                            //     return dist[nx][ny];
                            // }
                            q.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};