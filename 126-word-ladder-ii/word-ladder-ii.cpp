class Solution {
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> visited;
        queue<string> q;

        q.push(beginWord);
        visited[beginWord] = 0;
        dict.erase(beginWord);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int step = visited[curr];
            if (curr == endWord) {
                found = true;
                break;
            }

            string word = curr;
            for (int i = 0; i < word.length(); i++) {
                char orig = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (dict.count(word)) {
                        if (!visited.count(word)) {
                            visited[word] = step + 1;
                            q.push(word);
                            adj[word].push_back(curr);
                        } else if (visited[word] == step + 1) {
                            adj[word].push_back(curr);
                        }
                    }
                }
                word[i] = orig;
            }
        }

        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, adj, path, ans);
        }

        return ans;
    }

    private:
    void dfs(string curr, string& beginWord, unordered_map<string, vector<string>>& adj, vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> exactPath = path;
            reverse(exactPath.begin(), exactPath.end());
            ans.push_back(exactPath);
            return;
        }

        for (auto& prev : adj[curr]) {
            path.push_back(prev);
            dfs(prev, beginWord, adj, path, ans);
            path.pop_back();
        }
    }
};