class Solution {
private:
    int computeMinSwaps(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> current(2, 0), next(2, 0);

        for (int i = n - 1; i > 0; i--) {
            for (int swapped = 0; swapped < 2; swapped++) {
                int minSwaps = INT_MAX;
                int prevA = arr1[i - 1], prevB = arr2[i - 1];
                if (swapped) swap(prevA, prevB);

                if (arr1[i] > prevA && arr2[i] > prevB) {
                    minSwaps = next[0];
                }
                if (arr1[i] > prevB && arr2[i] > prevA) {
                    minSwaps = min(minSwaps, 1 + next[1]);
                }

                current[swapped] = minSwaps;
            }
            next = current;
        }

        return min(current[0], current[1]);
    }

public:
    int minSwap(vector<int>& arr1, vector<int>& arr2) {
        arr1.insert(arr1.begin(), -1);
        arr2.insert(arr2.begin(), -1);
        return computeMinSwaps(arr1, arr2);
    }
};