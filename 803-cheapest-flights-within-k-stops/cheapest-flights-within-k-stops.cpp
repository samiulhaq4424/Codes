class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(steps > k){
                continue;
            }
            for(auto itr : adj[node]){
                int v = itr.first;
                int wt = itr.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    q.push({steps+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        } else {
            return dist[dst];
        }
    }
};