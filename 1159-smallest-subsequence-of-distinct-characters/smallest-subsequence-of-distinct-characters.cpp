class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);

        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = "";

        for (char c : s) {
            count[c - 'a']--;

            if (visited[c - 'a']) continue;

            while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            visited[c - 'a'] = true;
        }

        return ans;
    }
};