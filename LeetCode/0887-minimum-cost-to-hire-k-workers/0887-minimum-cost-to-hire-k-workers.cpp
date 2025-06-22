class Solution {
public:
    double mincostToHireWorkers(vector<int>& qualities, vector<int>& salaries, int groupSize) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> minHeap;
        priority_queue<int> maxHeap;
        int totalWorkers = qualities.size();
        
        for (int i = 0; i < totalWorkers; i++) {
            minHeap.push({(double)salaries[i] / qualities[i], qualities[i]});
        }
        
        double totalQuality = 0;
        double minCost = numeric_limits<double>::max();
        
        while (!minHeap.empty()) {
            auto [ratio, quality] = minHeap.top();
            totalQuality += quality;
            maxHeap.push(quality);
            minHeap.pop();
            
            if (maxHeap.size() > groupSize) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (maxHeap.size() == groupSize) {
                minCost = min(minCost, totalQuality * ratio);
            }
        }
        
        return minCost;
    }
};