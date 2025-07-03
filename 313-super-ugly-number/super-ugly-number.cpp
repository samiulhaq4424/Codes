class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> ugly(n, 1); 
        int m = primes.size();
        vector<int> pointers(m, 0); 
        
        for (int i = 1; i < n; i++) {
            vector<long> nextMultiples(m);
            for (int j = 0; j < m; j++) {
                nextMultiples[j] = ugly[pointers[j]] * primes[j];
            }
            
            long nextUgly = *min_element(nextMultiples.begin(), nextMultiples.end());
            ugly[i] = nextUgly;
            
            for (int j = 0; j < m; j++) {
                if (nextMultiples[j] == nextUgly) {
                    pointers[j]++;
                }
            }
        }
        
        return static_cast<int>(ugly[n - 1]);
    }
};