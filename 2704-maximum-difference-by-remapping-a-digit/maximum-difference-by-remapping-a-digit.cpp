class Solution {
public:
    int minMaxDifference(int num) {
        string original = to_string(num);

        string highest = original;
        char replaceMax = 0;
        for (char ch : original) {
            if (ch != '9') {
                replaceMax = ch;
                break;
            }
        }
        if (replaceMax) {
            for (char& ch : highest) {
                if (ch == replaceMax) ch = '9';
            }
        }

        string lowest = original;
        char replaceMin = 0;
        for (char ch : original) {
            if (ch != '0') {
                replaceMin = ch;
                break;
            }
        }
        if (replaceMin) {
            for (char& ch : lowest) {
                if (ch == replaceMin) ch = '0';
            }
        }

        return stoi(highest) - stoi(lowest);
    }
};
