class Solution {
private:
    int minRounds[30][30][30], maxRounds[30][30][30];

public:
    pair<int, int> computeRounds(int total, int p1, int p2) {
        if (minRounds[total][p1][p2]) {
            return {minRounds[total][p1][p2], maxRounds[total][p1][p2]};
        }
        if (p1 + p2 == total + 1) {
            return {1, 1};
        }

        if (p1 + p2 > total + 1) {
            tie(minRounds[total][p1][p2], maxRounds[total][p1][p2]) = computeRounds(total, total + 1 - p2, total + 1 - p1);
            return {minRounds[total][p1][p2], maxRounds[total][p1][p2]};
        }

        int earliest = INT_MAX, latest = INT_MIN;
        int half = (total + 1) / 2;

        if (p2 <= half) {
            for (int i = 0; i < p1; ++i) {
                for (int j = 0; j < p2 - p1; ++j) {
                    auto [x, y] = computeRounds(half, i + 1, i + j + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        } else {
            int p2_prime = total + 1 - p2;
            int offset = (total - 2 * p2_prime + 1) / 2;
            for (int i = 0; i < p1; ++i) {
                for (int j = 0; j < p2_prime - p1; ++j) {
                    auto [x, y] = computeRounds(half, i + 1, i + j + offset + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }

        return {minRounds[total][p1][p2] = earliest + 1, maxRounds[total][p1][p2] = latest + 1};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(minRounds, 0, sizeof(minRounds));
        memset(maxRounds, 0, sizeof(maxRounds));

        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        auto [earliest, latest] = computeRounds(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};