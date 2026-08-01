class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);

        for (int i = 0; i < n; ++i) {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;

            change[low]++;
            change[high]--;
            if (low >= high) {
                change[0]++;
            }
        }

        int maxScore = -1;
        int bestK = 0;
        int currentScore = 0;

        for (int k = 0; k < n; ++k) {
            currentScore += change[k];
            if (currentScore > maxScore) {
                maxScore = currentScore;
                bestK = k;
            }
        }

        return bestK;
    }
};