class Solution {
public:
    vector<string> divideString(string input, int groupSize, char filler) {
        int len = input.length();
        vector<string> result;
        string current;
        int count = 0;

        for (int i = 0; i < len; i++) {
            current += input[i];
            count++;
            if (count == groupSize) {
                result.push_back(current);
                current = "";
                count = 0;
            }
        }

        if (!current.empty()) {
            while (count < groupSize) {
                current += filler;
                count++;
            }
            result.push_back(current);
        }

        return result;
    }
};