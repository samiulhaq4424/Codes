class Solution {
public:
    bool isNumber(string input) {
        return validateNumber(input);
    }

private:
    bool validateNumber(const string& input) {
        if (input.empty()) return false;

        size_t pos = 0;
        if (input[pos] == '+' || input[pos] == '-') pos++;

        bool hasDigitsBefore = false;
        while (pos < input.size() && isdigit(input[pos])) {
            hasDigitsBefore = true;
            pos++;
        }

        bool hasDigitsAfter = false;
        if (pos < input.size() && input[pos] == '.') {
            pos++;
            while (pos < input.size() && isdigit(input[pos])) {
                hasDigitsAfter = true;
                pos++;
            }
        }

        if (pos < input.size() && (input[pos] == 'e' || input[pos] == 'E')) {
            pos++;
            if (pos < input.size() && (input[pos] == '+' || input[pos] == '-')) pos++;
            if (pos >= input.size() || !isdigit(input[pos])) return false;
            while (pos < input.size() && isdigit(input[pos])) pos++;
        }

        return pos == input.size() && (hasDigitsBefore || hasDigitsAfter);
    }
};