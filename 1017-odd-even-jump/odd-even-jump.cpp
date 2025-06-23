class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), count = 1;
        vector<pair<bool, bool>> jumps(n);
        map<int, int> value_to_index;
        jumps[n - 1] = {true, true};
        
        for (int i = n - 1; i >= 0; --i) {
            auto it = value_to_index.lower_bound(A[i]);
            if (it != value_to_index.end()) {
                count += jumps[i].first = jumps[it->second].second;
                if (it->first == A[i]) ++it;
            }
            if (it != value_to_index.begin()) {
                jumps[i].second = jumps[prev(it)->second].first;
            }
            value_to_index[A[i]] = i;
        }
        
        return count;
    }
};