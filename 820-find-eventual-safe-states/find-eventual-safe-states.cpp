class Solution {
public:
    bool dfs(int sv, vector<int> &vis, vector<int> &path, vector<vector<int>>& graph) {
        vis[sv]=1;
        path[sv]=1;
        for(auto it : graph[sv]){
            if(!vis[it]){
                if(dfs(it,vis,path,graph) == true){
                    return true;
                }
            } else if(path[it] == 1){
                return true;
            }
        }
        path[sv]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,graph);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(path[i]==0){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};