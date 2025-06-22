class Solution {
 public:
  int superEggDrop(int k, int n) {
    dp.resize(k + 1, vector<int>(n + 1, -1));
    return drop(k, n);
  }

 private:
  vector<vector<int>> dp;

  int drop(int k, int n) {
    if (k == 0) return 0;
    if (k == 1) return n;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[k][n] != -1) return dp[k][n];

    int l = 1;
    int r = n + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      const int broken = drop(k - 1, m - 1);
      const int unbroken = drop(k, n - m);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }

    return dp[k][n] = 1 + drop(k - 1, l - 1);
  }
};