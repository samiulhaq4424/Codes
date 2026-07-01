class Solution {
public:
    struct TrieNode {
        int idx = -1;
        vector<int> p_idxs;
        TrieNode* ch[26] = {nullptr};
    };

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void insert(TrieNode* root, const string& s, int idx) {
        TrieNode* curr = root;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (isPalindrome(s, 0, i)) {
                curr->p_idxs.push_back(idx);
            }
            int c = s[i] - 'a';
            if (!curr->ch[c]) curr->ch[c] = new TrieNode();
            curr = curr->ch[c];
        }
        curr->idx = idx;
        curr->p_idxs.push_back(idx);
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            insert(root, words[i], i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            TrieNode* curr = root;
            string s = words[i];
            int len = s.length();
            bool matched = true;

            for (int j = 0; j < len; ++j) {
                if (curr->idx != -1 && curr->idx != i && isPalindrome(s, j, len - 1)) {
                    ans.push_back({i, curr->idx});
                }
                int c = s[j] - 'a';
                if (!curr->ch[c]) {
                    matched = false;
                    break;
                }
                curr = curr->ch[c];
            }

            if (matched) {
                for (int p_idx : curr->p_idxs) {
                    if (p_idx != i) {
                        ans.push_back({i, p_idx});
                    }
                }
            }
        }
        return ans;
    }
};