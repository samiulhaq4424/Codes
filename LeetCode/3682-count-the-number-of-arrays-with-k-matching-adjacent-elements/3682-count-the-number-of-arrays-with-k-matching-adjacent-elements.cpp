class Solution {
public:
    static const int MOD = 1e9 + 7;

    static long long power(long long base, int exponent, int modulus = MOD) {
        if (exponent == 0) return 1;
        long long temp = (exponent & 1) ? base : 1;
        return power(base * base % modulus, exponent >> 1, modulus) * temp % modulus;
    }

    static int inverse(int a, int modulus = MOD) {
        int x = 1, y = 0;
        int r = a, s = modulus;
        while (s != 0) {
            int q = r / s;
            int tempR = s, tempX = y;
            s = r - q * s;
            y = x - q * y;
            r = tempR;
            x = tempX;
        }
        if (x < 0) x += modulus;
        return x;
    }

    static long long binomial(int n, int k) {
        if (n < 2 * k) return binomial(n, n - k);
        long long denom = 1;
        for (int i = 1; i <= k; i++) {
            denom = denom * i % MOD;
        }
        long long result = inverse(denom);
        for (int i = n; i >= n - k + 1; i--) {
            result = result * i % MOD;
        }
        return result;
    }

    static int countGoodArrays(int n, int m, int k) {
        return m * power(m - 1, n - k - 1) % MOD * binomial(n - 1, k) % MOD;
    }
};