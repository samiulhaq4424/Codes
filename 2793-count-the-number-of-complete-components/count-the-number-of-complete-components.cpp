class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& v_count, int& e_count) {
        visited[node] = true;
        v_count++;
        e_count += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, v_count, e_count);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int v_count = 0;
                int e_count = 0;
                dfs(i, adj, visited, v_count, e_count);

                if (e_count == v_count * (v_count - 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};