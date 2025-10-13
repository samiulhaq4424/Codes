class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countFresh1 = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int, pair<int,int>>> q;
        for (int i = 0; i < n; i++) {
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                } else if(grid[i][j]==1) {
                    ++countFresh1;
                }
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int countFresh2=0;
        int minTime = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int time = it.first;
            int x = it.second.first;
            int y = it.second.second;
            minTime = max(minTime,time);
            for(int i=0;i<4;i++){
                int nx= x+dr[i];
                int ny= y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                    ++countFresh2;
                    vis[nx][ny]=1;
                    q.push({time+1,{nx,ny}});
                }
            }
        }
        if(countFresh1 != countFresh2){
            return -1;
        } else {
            return minTime;
        }
    }
};

