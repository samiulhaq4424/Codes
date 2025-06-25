class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) pos1++;
        while (pos2 < n2 && nums2[pos2] < 0) pos2++;
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i = 0, j = pos2 - 1; i < pos1 && j >= 0;) {
                if ((long long)nums1[i] * nums2[j] > mid) i++;
                else count += pos1 - i, j--;
            }
            for (int i = pos1, j = n2 - 1; i < n1 && j >= pos2;) {
                if ((long long)nums1[i] * nums2[j] > mid) j--;
                else count += j - pos2 + 1, i++;
            }
            for (int i = 0, j = pos2; i < pos1 && j < n2;) {
                if ((long long)nums1[i] * nums2[j] > mid) j++;
                else count += n2 - j, i++;
            }
            for (int i = pos1, j = 0; i < n1 && j < pos2;) {
                if ((long long)nums1[i] * nums2[j] > mid) i++;
                else count += n1 - i, j++;
            }
            if (count < k) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};