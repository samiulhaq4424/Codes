class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;
        
        queue<long long> q;
        unordered_map<long long, int> dist;
        q.push(n);
        dist[n] = 0;
        
        while (!q.empty()) {
            long long curr = q.front();
            q.pop();
            
            if (curr == 1) return dist[curr];
            
            if (curr % 2 == 0) {
                long long next = curr / 2;
                if (dist.find(next) == dist.end()) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            } else {
                long long next1 = curr + 1, next2 = curr - 1;
                if (dist.find(next1) == dist.end()) {
                    dist[next1] = dist[curr] + 1;
                    q.push(next1);
                }
                if (dist.find(next2) == dist.end()) {
                    dist[next2] = dist[curr] + 1;
                    q.push(next2);
                }
            }
        }
        
        return -1;
    }
};