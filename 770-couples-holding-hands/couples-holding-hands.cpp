class Solution {
public:
    int minSwapsCouples(vector<int>& seats) {
        int n = seats.size();
        vector<int> positions(n, -1);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            positions[seats[i]] = i;
        }

        for (int i = 0; i < n; i += 2) {
            while (abs(seats[i] - seats[i + 1]) != 1 || (seats[i] % 2 == 1 && seats[i] < seats[i + 1])) {
                int partner = (seats[i] % 2 == 0) ? seats[i] + 1 : seats[i] - 1;
                int partnerPos = positions[partner];
                int swapPos = (partnerPos % 2 == 0) ? partnerPos + 1 : partnerPos - 1;

                swap(seats[i], seats[swapPos]);
                positions[seats[i]] = i;
                positions[seats[swapPos]] = swapPos;
                swaps++;
            }
        }

        return swaps;
    }
};