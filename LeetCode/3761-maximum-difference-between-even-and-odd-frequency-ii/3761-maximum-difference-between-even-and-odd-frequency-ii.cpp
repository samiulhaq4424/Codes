class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int result = INT_MIN;
        
        for (char c1 = '0'; c1 <= '4'; ++c1) {
            for (char c2 = '0'; c2 <= '4'; ++c2) {
                if (c1 == c2) continue;
                
                vector<int> minDiff(4, INT_MAX);
                int count1 = 0, count2 = 0;
                int prevCount1 = 0, prevCount2 = 0;
                int left = -1;
                
                for (int right = 0; right < n; ++right) {
                    count1 += (s[right] == c1);
                    count2 += (s[right] == c2);
                    
                    while (right - left >= k && count2 - prevCount2 >= 2) {
                        ++left;
                        int status = ((prevCount1 & 1) << 1) | (prevCount2 & 1);
                        minDiff[status] = min(minDiff[status], prevCount1 - prevCount2);
                        prevCount1 += (s[left] == c1);
                        prevCount2 += (s[left] == c2);
                    }
                    
                    int currStatus = ((count1 & 1) << 1) | (count2 & 1);
                    if (minDiff[currStatus ^ 0b10] != INT_MAX) {
                        result = max(result, count1 - count2 - minDiff[currStatus ^ 0b10]);
                    }
                }
            }
        }
        
        return result == INT_MIN ? -1 : result;
    }
};