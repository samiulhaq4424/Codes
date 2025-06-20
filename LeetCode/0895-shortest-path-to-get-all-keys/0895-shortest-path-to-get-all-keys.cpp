class Solution {
public:
    int shortestPathAllKeys(vector<string>& maze) {
        int rows = maze.size(), cols = maze[0].size();
        int startX, startY, totalKeys = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (maze[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if (maze[i][j] >= 'a' && maze[i][j] <= 'z') totalKeys++;
            }
        }
        int keyMask = 0;
        map<pair<int, int>, unordered_set<int>> visited;
        queue<pair<pair<int, int>, int>> queue;
        queue.push({{startX, startY}, keyMask});
        visited[{startX, startY}].insert(keyMask);
        int steps = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!queue.empty()) {
            int levelSize = queue.size();
            while (levelSize--) {
                auto current = queue.front();
                queue.pop();
                int x = current.first.first, y = current.first.second;
                keyMask = current.second;
                if (maze[x][y] >= 'a' && maze[x][y] <= 'z') {
                    keyMask |= (1 << (maze[x][y] - 'a'));
                }
                if (keyMask == (1 << totalKeys) - 1) return steps;
                for (auto& dir : directions) {
                    int nextX = x + dir[0], nextY = y + dir[1];
                    if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols || maze[nextX][nextY] == '#') {
                        continue;
                    }
                    if (maze[nextX][nextY] >= 'A' && maze[nextX][nextY] <= 'Z' && 
                        !(keyMask & (1 << (maze[nextX][nextY] - 'A')))) {
                        continue;
                    }
                    if (visited[{nextX, nextY}].find(keyMask) == visited[{nextX, nextY}].end()) {
                        queue.push({{nextX, nextY}, keyMask});
                        visited[{nextX, nextY}].insert(keyMask);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};