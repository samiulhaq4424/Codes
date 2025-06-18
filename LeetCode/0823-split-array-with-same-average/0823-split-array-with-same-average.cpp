class Solution {
public:
    bool splitArraySameAverage(vector<int>& values) {
        int n = values.size();
        int totalSum = accumulate(values.begin(), values.end(), 0);

        for (int& val : values) {
            val = val * n - totalSum;
        }

        if (n == 1) return false;

        vector<int> firstHalf(values.begin(), values.begin() + n / 2);
        vector<int> secondHalf(values.begin() + n / 2, values.end());

        set<int> secondSums;
        int m2 = secondHalf.size();
        for (int mask = 1; mask < (1 << m2); mask++) {
            int subsetSum = 0;
            for (int i = 0; i < m2; i++) {
                if (mask & (1 << i)) subsetSum += secondHalf[i];
            }
            if (subsetSum == 0) return true;
            secondSums.insert(subsetSum);
        }

        int m1 = firstHalf.size();
        int firstTotal = accumulate(firstHalf.begin(), firstHalf.end(), 0);
        for (int mask = 1; mask < (1 << m1); mask++) {
            int subsetSum = 0;
            for (int i = 0; i < m1; i++) {
                if (mask & (1 << i)) subsetSum += firstHalf[i];
            }
            if (subsetSum == 0 || (subsetSum != firstTotal && secondSums.count(-subsetSum))) {
                return true;
            }
        }

        return false;
    }
};