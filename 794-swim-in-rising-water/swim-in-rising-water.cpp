class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y==n-1){
                return dis;
            }
            for(int i=0;i<4;i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int maxi = max(dis,grid[nx][ny]);
                    if(maxi < dist[nx][ny]){
                        dist[nx][ny] = maxi;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
       return dist[n-1][n-1];
    }
};