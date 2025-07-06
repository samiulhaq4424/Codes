class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }
        
        vector<double> results;
        for (auto& query : queries) {
            string start = query[0], end = query[1];
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }
            if (start == end) {
                results.push_back(1.0);
                continue;
            }
            
            unordered_set<string> visited;
            double result = dfs(start, end, graph, visited);
            results.push_back(result);
        }
        
        return results;
    }
    
private:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }
        
        visited.insert(start);
        for (auto& [next, value] : graph[start]) {
            if (visited.find(next) == visited.end()) {
                double subResult = dfs(next, end, graph, visited);
                if (subResult != -1.0) {
                    return value * subResult;
                }
            }
        }
        
        return -1.0;
    }
};