class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);
        vector<bool> visited(n, false);
        unordered_map<long long, int> edgeMoves;
        int reachableCount = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            graph[u].emplace_back(v, length);
            graph[v].emplace_back(u, length);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [movesUsed, vertex] = pq.top();
            pq.pop();

            if (visited[vertex]) continue;
            visited[vertex] = true;
            reachableCount++;
            if (movesUsed == maxMoves) continue;

            for (const auto& [neighbor, edgeLength] : graph[vertex]) {
                if (!visited[neighbor]) {
                    int nextMoves = movesUsed + edgeLength + 1;
                    if (nextMoves <= maxMoves) {
                        pq.emplace(nextMoves, neighbor);
                        reachableCount += edgeLength;
                    } else {
                        edgeMoves[static_cast<long long>(neighbor) << 32 | vertex] = maxMoves - movesUsed;
                    }
                } else {
                    long long edgeKey = static_cast<long long>(vertex) << 32 | neighbor;
                    if (edgeMoves.count(edgeKey)) {
                        reachableCount += min(maxMoves - movesUsed + edgeMoves[edgeKey], edgeLength);
                        edgeMoves.erase(edgeKey);
                    }
                }
            }
        }

        for (const auto& [_, moves] : edgeMoves) {
            reachableCount += moves;
        }

        return reachableCount;
    }
};