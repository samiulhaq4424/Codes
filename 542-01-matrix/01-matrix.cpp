class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int x = it.second.first;
            int y = it.second.second;
            dist[x][y] = steps;
            for(int i=0;i<4;i++){
                int nx = x+dr[i];
                int ny = y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 & !vis[nx][ny]){
                    q.push({steps+1,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }
        return dist;
    }
};