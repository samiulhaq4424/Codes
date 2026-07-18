class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> tCount(128, 0);
        for (char c : t) tCount[c]++;

        vector<int> windowCount(128, 0);
        int required = 0;
        for (int count : tCount) {
            if (count > 0) required++;
        }

        int left = 0, right = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            if (tCount[c] > 0 && windowCount[c] == tCount[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                windowCount[c]--;
                if (tCount[c] > 0 && windowCount[c] < tCount[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};