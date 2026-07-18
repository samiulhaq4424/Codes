class Solution {
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        vector<string> res;
        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> subRes = dfs(s.substr(i), dict);
                for (string sub : subRes) {
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        return memo[s] = res;
    }

    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};