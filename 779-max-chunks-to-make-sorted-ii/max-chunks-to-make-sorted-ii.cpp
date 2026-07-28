class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> minRight(n);

        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }

        int chunks = 0;
        int maxLeft = INT_MIN;

        for (int i = 0; i < n - 1; ++i) {
            maxLeft = max(maxLeft, arr[i]);
            if (maxLeft <= minRight[i + 1]) {
                chunks++;
            }
        }

        return chunks + 1;
    }
};