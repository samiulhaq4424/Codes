class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) return -1;
        
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited;
        visited.insert(startGene);
        int mutations = 0;
        
        char genes[4] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == endGene) return mutations;
                
                for (int j = 0; j < 8; j++) {
                    char original = curr[j];
                    for (char gene : genes) {
                        if (gene == original) continue;
                        curr[j] = gene;
                        if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = original;
                }
            }
            mutations++;
        }
        
        return -1;
    }
};