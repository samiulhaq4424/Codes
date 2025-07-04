class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        a %= MOD;
        int result = 1;
        for (int digit : b) {
            int temp = result;
            result = 1;
            for (int i = 0; i < 10; i++) {
                result = (result * temp) % MOD;
            }
            if (digit > 0) {
                int pow_a = 1;
                for (int i = 0; i < digit; i++) {
                    pow_a = (pow_a * a) % MOD;
                }
                result = (result * pow_a) % MOD;
            }
        }
        return result;
    }
};