class Solution {
public:
    int distances[15][15];
    int memo[1<<13][13];
    
    void computeShortestPaths(int size) {
        for (int k = 0; k < size; k++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
    }
    
    int findMinPath(int size) {
        memset(memo, 0x3f, sizeof(memo));
        for (int i = 0; i < size; i++)
            memo[1<<i][i] = 0;
        for (int mask = 1; mask < (1<<size); mask++)
            for (int u = 0; u < size; u++)
                for (int v = 0; v < size; v++) {
                    int srcBit = 1 << u, dstBit = 1 << v;
                    if ((mask & srcBit) && !(mask & dstBit))
                        memo[mask | dstBit][v] = min(memo[mask][u] + distances[u][v], memo[mask | dstBit][v]);
                }
        int shortest = 0x3f3f3f3f;
        for (int i = 0; i < size; i++)
            shortest = min(memo[(1<<size)-1][i], shortest);
        return shortest;
    }
    
    int shortestPathLength(vector<vector<int>>& adjList) {
        int size = adjList.size();
        memset(distances, 0x3f, sizeof(distances));
        for (int i = 0; i < size; i++) {
            for (int v : adjList[i]) {
                distances[i][v] = 1;
            }
        }
        computeShortestPaths(size);
        return findMinPath(size);
    }
};