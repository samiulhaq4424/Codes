class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            for(auto itr : adj[node]){
                int v = itr.first;
                int wt = itr.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i=1;i<n+1;i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};