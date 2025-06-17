class Solution {
public:
    string smallestGoodBase(string input) {
        using ull = unsigned long long;
        ull number = stoull(input);
        
        for (ull len = log2(number + 1); len >= 2; --len) {
            ull low = 2, high = pow(number, 1.0 / (len - 1)) + 1;
            while (low <= high) {
                ull mid = low + (high - low) / 2;
                ull total = 0, term = 1;
                for (ull i = 0; i < len; ++i) {
                    total += term;
                    if (i < len - 1 && term > number / mid) break;
                    term *= mid;
                }
                if (total < number) low = mid + 1;
                else if (total > number) high = mid - 1;
                else return to_string(mid);
            }
        }
        return to_string(number - 1);
    }
};