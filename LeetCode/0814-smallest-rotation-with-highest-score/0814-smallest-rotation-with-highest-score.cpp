class Solution {
public:
    int bestRotation(vector<int>& values) {
        int n = values.size();
        int score = 0;
        priority_queue<int, vector<int>, greater<int>> transitions;
        
        for (int i = 0; i < n; i++) {
            if (values[i] <= i) {
                score++;
                transitions.push(i - values[i]);
            }
        }
        
        int bestScore = score;
        int bestK = 0;
        
        for (int k = 1; k < n; k++) {
            while (!transitions.empty() && k > transitions.top()) {
                transitions.pop();
                score--;
            }
            
            if (values[k - 1] <= n - 1) {
                score++;
                transitions.push(k + (n - 1) - values[k - 1]);
            }
            
            if (score > bestScore) {
                bestScore = score;
                bestK = k;
            }
        }
        
        return bestK;
    }
};