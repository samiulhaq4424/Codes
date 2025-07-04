class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        using P = pair<long long, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> pq; 
        set<pair<int, int>> visited; 
        
        pq.push({(long long)nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});
        
        while (k-- > 0 && !pq.empty()) {
            auto [sum, indices] = pq.top();
            pq.pop();
            int i = indices.first, j = indices.second;
            
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size() && visited.find({i, j + 1}) == visited.end()) {
                pq.push({(long long)nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
            
            if (i + 1 < nums1.size() && visited.find({i + 1, j}) == visited.end()) {
                pq.push({(long long)nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }
        
        return result;
    }
};