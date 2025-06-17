class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& values, int windowSize) {
        int n = values.size();
        int medianIndex = windowSize - windowSize / 2 - 1;
        vector<double> results(n - windowSize + 1);
        multiset<int> window(values.begin(), values.begin() + windowSize);
        auto medianIt = next(window.begin(), medianIndex);

        for (int i = windowSize; i <= n; ++i) {
            results[i - windowSize] = (static_cast<double>(*medianIt) + (windowSize % 2 ? *medianIt : *next(medianIt))) / 2;
            if (i < n) {
                int adjust = INT_MAX;
                if (windowSize > 2) {
                    if ((values[i - windowSize] < *medianIt && values[i] < *medianIt) || 
                        (values[i - windowSize] > *medianIt && values[i] > *medianIt)) adjust = 0;
                    else if (values[i - windowSize] < *medianIt && values[i] > *medianIt) adjust = 1;
                    else if (values[i - windowSize] > *medianIt && values[i] < *medianIt) adjust = -1;
                }
                window.insert(values[i]);
                window.erase(window.find(values[i - windowSize]));
                if (adjust == INT_MAX) medianIt = next(window.begin(), medianIndex);
                else if (adjust == 1) ++medianIt;
                else if (adjust == -1) --medianIt;
            }
        }
        return results;
    }
};