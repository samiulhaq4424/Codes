class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[x][y]=1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx = x+dr[i];
            int ny = y+dc[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='O' && !vis[nx][ny]){
                dfs(nx,ny,vis,grid);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,board);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};