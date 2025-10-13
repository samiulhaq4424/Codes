class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[x][y] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x+dr[i];
            int ny = y+dc[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1' && !vis[nx][ny]){
                dfs(nx,ny,n,m,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,n,m,vis,grid);
                    ++count;
                }
            }
        }
        return count;
    }
};