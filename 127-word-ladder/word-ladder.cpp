class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<int, string>> q;
        q.push({1, beginWord});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int step = it.first;
            string word = it.second;
            if(word == endWord){
                return step;
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word) > 0) {
                        q.push({step+1,word});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};