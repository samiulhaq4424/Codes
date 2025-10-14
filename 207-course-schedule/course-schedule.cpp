class Solution {
public:
    bool dfs(int sv, vector<int> &vis, vector<int> &path, vector<int> adj[]){
        vis[sv]=1;
        path[sv]=1;
        for(auto it : adj[sv]){
            if(!vis[it]){
                if(dfs(it,vis,path,adj) == false){
                    return false;
                }
            } else if(path[it] == 1){
                return false;
            }
        }
        path[sv]=0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};