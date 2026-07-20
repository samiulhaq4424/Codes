class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int num = words.size();
        if (n == 0 || num == 0) return ans;

        int len = words[0].size();
        int totalLen = num * len;
        if (n < totalLen) return ans;

        unordered_map<string, int> wordCount;
        for (const string& w : words) {
            wordCount[w]++;
        }

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= n - len; j += len) {
                string sub = s.substr(j, len);

                if (wordCount.count(sub)) {
                    seen[sub]++;
                    count++;

                    while (seen[sub] > wordCount[sub]) {
                        string leftSub = s.substr(left, len);
                        seen[leftSub]--;
                        count--;
                        left += len;
                    }

                    if (count == num) {
                        ans.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return ans;
    }
};