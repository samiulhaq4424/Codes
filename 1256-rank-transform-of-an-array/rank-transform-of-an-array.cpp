class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        unordered_map<int, int> rank;
        int current_rank = 1;

        for (int num : sorted_arr) {
            if (rank.find(num) == rank.end()) {
                rank[num] = current_rank;
                current_rank++;
                }
            }
            
            vector<int> ans(arr.size());
            for (int i = 0; i < arr.size(); i++) {
                ans[i] = rank[arr[i]];
                }
                
                return ans;               }
};