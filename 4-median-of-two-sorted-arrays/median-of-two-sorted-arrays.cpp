class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        int totalSize = merged.size();
        if (totalSize % 2 == 1) {
            return merged[totalSize / 2];
        } else {
            return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
        }
    }
};