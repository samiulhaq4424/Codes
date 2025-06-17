class Solution {
public:
    int strongPasswordChecker(string input) {
        int len = input.size();
        if (!len) return 6;

        int sequenceLen = 1;
        int substitutions = 0;
        int deletions = 0;
        int insertions = 0;
        char current = input[0];
        int hasLower = (current >= 'a' && current <= 'z');
        int hasUpper = (current >= 'A' && current <= 'Z');
        int hasDigit = (current >= '0' && current <= '9');
        vector<int> sequences;

        for (int i = 1; i < len; ++i) {
            hasLower += (input[i] >= 'a' && input[i] <= 'z');
            hasUpper += (input[i] >= 'A' && input[i] <= 'Z');
            hasDigit += (input[i] >= '0' && input[i] <= '9');
            if (input[i] == current) {
                ++sequenceLen;
            } else {
                substitutions += sequenceLen / 3;
                insertions += (sequenceLen - 1) / 2;
                deletions += max(0, sequenceLen - 2);
                if (sequenceLen > 2) sequences.push_back(sequenceLen);
                sequenceLen = 1;
                current = input[i];
            }
        }
        substitutions += sequenceLen / 3;
        insertions += (sequenceLen - 1) / 2;
        deletions += max(0, sequenceLen - 2);
        if (sequenceLen > 2) sequences.push_back(sequenceLen);

        int missing = (!hasLower) + (!hasUpper) + (!hasDigit);

        if (len < 6) return max(max(6 - len, missing), insertions);
        if (len <= 20) return max(substitutions, missing);

        int excess = len - 20;
        if (excess >= deletions) return excess + missing;

        int R = excess;
        int m = sequences.size();
        vector<vector<int>> memo(R + 1, vector<int>(m + 1, INT_MAX));
        memo[0][0] = 0;
        for (int j = 1; j <= m; ++j) {
            memo[0][j] = memo[0][j - 1] + sequences[j - 1] / 3;
        }
        for (int r = 1; r <= R; ++r) {
            for (int j = 1; j <= m; ++j) {
                for (int s = 0; s <= min(sequences[j - 1] - 2, r); ++s) {
                    if (memo[r - s][j - 1] < INT_MAX) {
                        memo[r][j] = min(memo[r][j], memo[r - s][j - 1] + (sequences[j - 1] - s) / 3);
                    }
                }
            }
        }
        return excess + max(memo[R][m], missing);
    }
};