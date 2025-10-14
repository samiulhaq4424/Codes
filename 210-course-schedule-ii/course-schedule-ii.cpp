class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        } else {
            return ans;
        }
    }
};