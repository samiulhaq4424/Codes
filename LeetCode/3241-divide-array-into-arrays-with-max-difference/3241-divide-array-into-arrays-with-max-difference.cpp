class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& values, int maxDiff) {
        int size = values.size();
        vector<int> counts(100001, 0);
        int largest = 0;

        for (int num : values) {
            counts[num]++;
            largest = max(largest, num);
        }

        vector<vector<int>> result;
        vector<int> currentGroup;
        int elementCount = 0;
        int groupMin = 0;

        for (int num = 1; num <= largest; num++) {
            while (counts[num] > 0) {
                counts[num]--;
                if (elementCount % 3 == 0) {
                    groupMin = num;
                }
                if (num > groupMin + maxDiff) {
                    return {};
                }
                currentGroup.push_back(num);
                elementCount++;
                if (elementCount % 3 == 0) {
                    result.push_back(currentGroup);
                    currentGroup.clear();
                }
            }
        }

        return elementCount == size ? result : vector<vector<int>>();
    }
};