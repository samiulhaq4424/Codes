class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for (const string& word : dictionary) {
            int i = 0, j = 0;
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    j++;
                }
                i++;
            }
            if (j == word.length()) {
                if (word.length() > result.length() || (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }
        return result;
    }
};