class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        
        int windowSize = p.length();
        for (int i = 0; i < windowSize; i++) sCount[s[i] - 'a']++;
        
        if (sCount == pCount) result.push_back(0);
        
        for (int i = windowSize; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - windowSize] - 'a']--;
            if (sCount == pCount) result.push_back(i - windowSize + 1);
        }
        
        return result;
    }
};