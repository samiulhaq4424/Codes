class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1;
        vector<int> lengths;
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j + 1 < n && word[j] == word[j + 1]) {
                j++;
            }
            int len = j - i + 1;
            if (len > 1) {
                lengths.push_back(len);
            }
            i = j + 1;
        }
        
        for (int len : lengths) {
            count += len - 1;
        }
        
        return count;
    }
};