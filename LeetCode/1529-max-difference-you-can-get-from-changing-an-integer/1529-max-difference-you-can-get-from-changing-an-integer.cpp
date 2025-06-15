class Solution {
public:
    int maxDiff(int num) {
        string original = to_string(num);
        string minNum = original;
        string maxNum = original;
        
        char minTarget = 0, maxTarget = 0;
        char minReplace = 0;

        for (int i = 0; i < original.size(); ++i) {
            if (!minTarget) {
                if (original[0] != '1') {
                    minTarget = original[0];
                    minReplace = '1';
                    minNum[0] = '1';
                } else if (original[i] != '0' && original[i] != original[0]) {
                    minTarget = original[i];
                    minReplace = '0';
                    minNum[i] = '0';
                }
            } else if (original[i] == minTarget) {
                minNum[i] = minReplace;
            }

            if (!maxTarget && original[i] != '9') {
                maxTarget = original[i];
                maxNum[i] = '9';
            } else if (original[i] == maxTarget) {
                maxNum[i] = '9';
            }
        }
        
        return stoi(maxNum) - stoi(minNum);
    }
};
