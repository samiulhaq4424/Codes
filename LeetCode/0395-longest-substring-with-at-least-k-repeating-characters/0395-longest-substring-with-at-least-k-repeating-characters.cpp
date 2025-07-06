class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || k > n) return 0;
        if (k <= 1) return n;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        int l = 0;
        while (l < n && freq[s[l]] >= k) l++;
        if (l >= n) return n;
        
        int left = longestSubstring(s.substr(0, l), k);
        while (l < n && freq[s[l]] < k) l++;
        int right = longestSubstring(s.substr(l), k);
        
        return max(left, right);
    }
};