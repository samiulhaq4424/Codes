class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmasks(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                bitmasks[i] |= (1 << (c - 'a'));
            }
        }
        
        int maxProd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((bitmasks[i] & bitmasks[j]) == 0) {
                    int prod = words[i].length() * words[j].length();
                    maxProd = max(maxProd, prod);
                }
            }
        }
        
        return maxProd;
    }
};