class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int maxEvents = 0, i = 0;
        int n = events.size();
        
        for (int day = 1; day <= 100000; day++) {
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                pq.pop();
                maxEvents++;
            }
        }
        
        return maxEvents;
    }
};