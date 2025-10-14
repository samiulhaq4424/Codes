class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int u = it.second;
            for(auto itr : adj[u]){
                int v = itr.first;
                int wt = itr.second;
                if(dis + wt < dist[v]){
                    ways[v]=ways[u];
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                } else if(dis + wt == dist[v]){
                    ways[v] = (ways[u] + ways[v])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};