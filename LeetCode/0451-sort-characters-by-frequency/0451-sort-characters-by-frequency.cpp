class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        vector<pair<char, int>> freq_vec(freq.begin(), freq.end());
        sort(freq_vec.begin(), freq_vec.end(), 
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second || (a.second == b.second && a.first > b.first);
             });
        
        string result;
        for (const auto& p : freq_vec) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};