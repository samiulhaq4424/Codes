class Solution {
public:
    int consecutiveNumbersSum(int target) {
        int result = 1, factorCount;
        while (target % 2 == 0) 
            target /= 2;
        for (int i = 3; i <= target; result *= factorCount + 1, i += 2) {
            for (factorCount = 0; target % i == 0; target /= i, factorCount++);
        }
        return target == 1 ? result : result * 2;
    }
};