class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n,vector<int>(n,1e9));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjMatrix[u][v] = wt;
            adjMatrix[v][u] = wt;
        }
        
        for(int i=0;i<n;i++){
            adjMatrix[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjMatrix[i][k]==1e9 || adjMatrix[k][j]==1e9){
                        continue;
                    }
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }

        int cityNo=-1,cityCount=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adjMatrix[i][j] <= distanceThreshold){
                    ++count;
                }
            }
            if(count <= cityCount){
                cityNo = i;
                cityCount = count;
            }
        }
        return cityNo;
    }
};