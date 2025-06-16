class Solution {
public:
    int calculate(string expr) {
        stack<int> signs;
        signs.push(1); // Initialize with positive sign
        int result = 0;
        int number = 0;
        int currentSign = 1;

        for (char c : expr) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '(') {
                signs.push(currentSign);
            } else if (c == ')') {
                signs.pop();
            } else if (c == '+' || c == '-') {
                result += number * currentSign;
                currentSign = (c == '+' ? 1 : -1) * signs.top();
                number = 0;
            }
        }

        result += number * currentSign;
        return result;
    }
};