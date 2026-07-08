class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& Q) {
        long long MOD = 1000000007;
        int n = s.size();

        vector<long long> P(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            P[i] = (P[i - 1] * 10) % MOD;
        }

        vector<int> S(n + 1, 0);
        vector<int> Z(n + 1, 0);
        vector<long long> V(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            S[i] = S[i - 1] + d;
            Z[i] = Z[i - 1] + (d > 0 ? 1 : 0);

            if (d > 0) {
                V[i] = (V[i - 1] * 10 + d) % MOD;
            } else {
                V[i] = V[i - 1];
            }
        }

        vector<int> ans;
        for (size_t i = 0; i < Q.size(); i++) {
            int l = Q[i][0];
            int r = Q[i][1];

            int nz = Z[r + 1] - Z[l];
            int sm = S[r + 1] - S[l];

            long long h = (V[l] * P[nz]) % MOD;
            long long x = (V[r + 1] - h + MOD) % MOD;

            long long res = (x * sm) % MOD;
            ans.push_back(res);
        }

        return ans;
    }
};