class Solution {
public:
    void reverse(vector<int>& N, int s, int e) {
        while (s < e) {
            int tmp = N[s];
            N[s] = N[e];
            N[e] = tmp;
            s++;
            e--;
        }
    }

    void rotate(vector<int>& N, int k) {
        int n = N.size();
        k = k % n;
        if (k == 0) return;

        reverse(N, 0, n - 1);
        reverse(N, 0, k - 1);
        reverse(N, k, n - 1);
    }
};