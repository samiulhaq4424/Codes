class Solution {
public:
    // Check if `target` is a subsequence of `s`
    bool isSubsequence(const string& s, const string& target) {
        int j = 0;
        for (char c : s) {
            if (c == target[j]) {
                j++;
                if (j == target.size()) return true;
            }
        }
        return false;
    }

    // Check if seq * k is a subsequence of s
    bool isValid(const string& s, const string& seq, int k) {
        string temp;
        for (int i = 0; i < k; ++i)
            temp += seq;
        return isSubsequence(s, temp);
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Candidate characters with freq >= k
        vector<char> chars;
        for (char c = 'z'; c >= 'a'; --c)
            if (freq[c] >= k)
                chars.push_back(c);

        int maxLen = s.size() / k;
        queue<string> q;
        q.push("");

        string result = "";

        while (!q.empty()) {
            string cur = q.front(); q.pop();

            for (char c : chars) {
                string next = cur + c;
                if (next.size() > maxLen) continue;

                if (isValid(s, next, k)) {
                    if (next.size() > result.size() || (next.size() == result.size() && next > result)) {
                        result = next;
                    }
                    q.push(next);
                }
            }
        }

        return result;
    }
};
