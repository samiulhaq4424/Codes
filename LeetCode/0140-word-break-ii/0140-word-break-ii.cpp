class Solution {
public:
    unordered_map<int, vector<string>> memo;

    vector<string> segmentString(string& input, int pos, unordered_set<string>& wordSet) {
        if (memo.find(pos) != memo.end()) return memo[pos];
        vector<string> combinations;

        if (pos == input.size()) {
            combinations.emplace_back("");
            return combinations;
        }

        for (int i = pos + 1; i <= input.size(); i++) {
            string candidate = input.substr(pos, i - pos);
            if (wordSet.find(candidate) != wordSet.end()) {
                vector<string> subResults = segmentString(input, i, wordSet);
                for (const string& sub : subResults) {
                    combinations.emplace_back(sub.empty() ? candidate : candidate + " " + sub);
                }
            }
        }

        return memo[pos] = combinations;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return segmentString(s, 0, wordSet);
    }
};