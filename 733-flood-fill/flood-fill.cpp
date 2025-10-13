class Solution {
public:
    void dfs(int x, int y, int color, int oldColor, vector<vector<int>>& image, vector<vector<int>>& ans){
        ans[x][y] = color;
        int n = image.size();
        int m = image[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dr[i];
            int ny=y+dc[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==oldColor && ans[nx][ny]!=color){
                dfs(nx,ny,color,oldColor,image,ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        dfs(sr,sc,color,oldColor,image,ans);
        return ans;
    }
};