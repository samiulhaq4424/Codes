class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a;
        int b = 1;
        for (int i = 1; i <= n; ++i) {
            a.push_back(i);
            if (i < n) {
                b *= i;
            }
        }
        
        k--;
        string s = "";
        
        for (int i = 0; i < n; ++i) {
            int c = k / b;
            s += to_string(a[c]);
            a.erase(a.begin() + c);
            if (i < n - 1) {
                k %= b;
                b /= (n - 1 - i);
            }
        }
        
        return s;

    }
};