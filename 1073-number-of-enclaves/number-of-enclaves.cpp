class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[x][y]=1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx = x+dr[i];
            int ny = y+dc[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(nx,ny,n,m,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,n,m,vis,grid);
            }
            if(grid[n-1][j] && !vis[n-1][j]){
                dfs(n-1,j,n,m,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0] &&!vis[i][0]){
                dfs(i,0,n,m,vis,grid);
            }
            if(grid[i][m-1] && !vis[i][m-1]){
                dfs(i,m-1,n,m,vis,grid);
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ++count;
                }
            }
        }
        return count;
    }
};