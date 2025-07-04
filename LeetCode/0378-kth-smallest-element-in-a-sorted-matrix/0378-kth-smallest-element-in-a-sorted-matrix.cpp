class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> pq; 
        set<pair<int, int>> visited; 
        

        pq.push({matrix[0][0], {0, 0}});
        visited.insert({0, 0});
        
        int result = 0;
        while (k-- > 0 && !pq.empty()) {
            auto [val, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;
            result = val; 
            

            if (col + 1 < n && visited.find({row, col + 1}) == visited.end()) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
                visited.insert({row, col + 1});
            }
      
            if (row + 1 < n && visited.find({row + 1, col}) == visited.end()) {
                pq.push({matrix[row + 1][col], {row + 1, col}});
                visited.insert({row + 1, col});
            }
        }
        
        return result;
    }
};