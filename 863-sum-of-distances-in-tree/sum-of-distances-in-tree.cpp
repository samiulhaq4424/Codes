class Solution {
public:
    int totalDist = 0;
    int traverse(vector<int> graph[], int curr, vector<int>& visited, vector<int>& edgeCounts, int depth) {
        int nodes = 0;
        totalDist += depth;
        visited[curr] = 1;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                nodes += 1 + traverse(graph, neighbor, visited, edgeCounts, depth + 1);
                edgeCounts[curr] = nodes;
            }
        }
        return nodes;
    }
    void propagate(vector<int> graph[], int curr, int size, vector<int>& edgeCounts, vector<int>& visited, vector<int>& distances) {
        visited[curr] = 1;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                distances[neighbor] = distances[curr] - edgeCounts[neighbor] + size - 2 - edgeCounts[neighbor];
                propagate(graph, neighbor, size, edgeCounts, visited, distances);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int size, vector<vector<int>>& connections) {
        vector<int> graph[size];
        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> edgeCounts(size, 0);
        vector<int> visited(size, 0);
        vector<int> distances(size, 0);
        traverse(graph, 0, visited, edgeCounts, 0);
        distances[0] = totalDist;
        vector<int> visitedAgain(size, 0);
        propagate(graph, 0, size, edgeCounts, visitedAgain, distances);
        return distances;
    }
};