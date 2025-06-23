class Solution {
public:
    int countTriplets(vector<int>& A) {
        int result = 0;
        int size = A.size();
        set<int> firstRound;
        vector<int> histogram(1 << 16);

        for (int i = 0; i < size; i++) {
            int val = A[i];
            firstRound.insert(val);
            histogram[val]++;
        }

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int val = A[i] & A[j];
                firstRound.insert(val);
                histogram[val] += 2;
            }
        }

        for (int i = 0; i < size; i++) {
            for (int val : firstRound) {
                if ((val & A[i]) == 0) {
                    result += histogram[val];
                }
            }
        }

        return result;
    }
};