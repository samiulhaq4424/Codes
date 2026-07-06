class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        vector<int> left(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            if (profit > left[i - 1]) {
                left[i] = profit;
            } else {
                left[i] = left[i - 1];
            }
        }

        vector<int> right(n, 0);
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
            }
            int profit = maxPrice - prices[i];
            if (profit > right[i + 1]) {
                right[i] = profit;
            } else {
                right[i] = right[i + 1];
            }
        }

        int maxTotalProfit = 0;
        for (int i = 0; i < n; i++) {
            int currentProfit = left[i] + right[i];
            if (currentProfit > maxTotalProfit) {
                maxTotalProfit = currentProfit;
            }
        }

        return maxTotalProfit;
    }
};