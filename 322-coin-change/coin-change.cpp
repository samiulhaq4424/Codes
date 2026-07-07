class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> records(amount + 1, amount + 1);
        records[0] = 0;

        for (int tracker = 1; tracker <= amount; tracker++) {
            for (int index = 0; index < coins.size(); index++) {
                if (coins[index] <= tracker) {
                    int remaining = records[tracker - coins[index]] + 1;
                    if (remaining < records[tracker]) {
                        records[tracker] = remaining;
                    }
                }
            }
        }

        if (records[amount] > amount) {
            return -1;
        }
        return records[amount];
    }
};