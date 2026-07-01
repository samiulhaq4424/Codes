class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> d(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (d[nr][nc] > d[r][c] + 1) {
                        d[nr][nc] = d[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> v(n, vector<int>(n, -1));

        pq.push({d[0][0], {0, 0}});
        v[0][0] = d[0][0];

        while (!pq.empty()) {
            auto [s, p] = pq.top();
            pq.pop();
            
            int r = p.first;
            int c = p.second;

            if (r == n - 1 && c == n - 1) return s;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int ns = min(s, d[nr][nc]);
                    if (ns > v[nr][nc]) {
                        v[nr][nc] = ns;
                        pq.push({ns, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};