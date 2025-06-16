class Solution {
public:
    
    vector<int> getMaxSubsequence(int len, vector<int>& arr) {
        int n = arr.size();
        if (len > n) return {}; 
        vector<int> result;
        int toRemove = n - len; 
        result.push_back(arr[0]);
        
        for (int i = 1; i < n; i++) {
            while (!result.empty() && arr[i] > result.back() && toRemove > 0) {
                result.pop_back();
                toRemove--;
            }
            result.push_back(arr[i]);
        }
        while (toRemove--) {
            result.pop_back();
        }
        return result;
    }

    void combineSequences(vector<int>& result, vector<int>& seq1, vector<int>& seq2) {
        int m = seq1.size(), n = seq2.size();
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (seq1[i] == seq2[j]) {
                int p = i, q = j;
                while (p < m && q < n && seq1[p] == seq2[q]) {
                    p++; q++;
                }
                if (q == n || (p < m && seq1[p] > seq2[q])) {
                    result.push_back(seq1[i++]);
                } else {
                    result.push_back(seq2[j++]);
                }
            } else if (seq1[i] > seq2[j]) {
                result.push_back(seq1[i++]); 
            } else {
                result.push_back(seq2[j++]); 
            }
        }
        while (i < m) result.push_back(seq1[i++]);
        while (j < n) result.push_back(seq2[j++]);
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> finalResult;
        for (int i = 0; i <= k; i++) {
            vector<int> subseq1 = getMaxSubsequence(i, nums1);
            vector<int> subseq2 = getMaxSubsequence(k - i, nums2);
            vector<int> merged;
            combineSequences(merged, subseq1, subseq2);
            if (merged.size() == k) finalResult = max(finalResult, merged);
        }
        return finalResult;
    }
};