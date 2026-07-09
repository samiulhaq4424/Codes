class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<int> index_to_count(len2 + 1, 0);
        vector<int> index_to_next(len2 + 1, 0);

        int s2_idx = 0, s2_cnt = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 0; j < len1; j++) {
                if (s1[j] == s2[s2_idx]) {
                    s2_idx++;
                    if (s2_idx == len2) {
                        s2_cnt++;
                        s2_idx = 0;
                    }
                }
            }

            index_to_count[i] = s2_cnt;
            index_to_next[i] = s2_idx;

            for (int prev = 0; prev < i; prev++) {
                if (index_to_next[prev] == s2_idx) {
                    int prev_count = index_to_count[prev];
                    int pattern_count = (index_to_count[i] - index_to_count[prev]) * ((n1 - prev) / (i - prev));
                    int rem_count = index_to_count[prev + (n1 - prev) % (i - prev)] - index_to_count[prev];
                    return (prev_count + pattern_count + rem_count) / n2;
                }
            }
        }

        return index_to_count[n1] / n2;
    }
};