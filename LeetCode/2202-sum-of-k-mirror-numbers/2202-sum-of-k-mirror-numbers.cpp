class Solution {
public:
    long long kMirror(int k, int n) {
        vector<long long> kMirrors;
        
        for (int len = 1; kMirrors.size() < n; len++) {
            generatePalindromes(len, k, kMirrors, n);
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += kMirrors[i];
        }
        
        return sum;
    }
    
private:
    void generatePalindromes(int len, int k, vector<long long>& kMirrors, int n) {
        if (kMirrors.size() >= n) return;
        
        int halfLen = (len + 1) / 2;
        long long start = pow(10, halfLen - 1);
        long long end = pow(10, halfLen) - 1;
        
        for (long long i = start; i <= end && kMirrors.size() < n; i++) {
            long long palindrome = createPalindrome(i, len % 2 == 0);
            if (isPalindrome(palindrome, k)) {
                kMirrors.push_back(palindrome);
            }
        }
    }
    
    long long createPalindrome(long long half, bool evenLength) {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        if (!evenLength) {
            rev = rev.substr(1);
        }
        
        return stoll(s + rev);
    }
    
    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        long long temp = num;
        
        while (temp > 0) {
            digits.push_back(temp % base);
            temp /= base;
        }
        
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left] != digits[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};