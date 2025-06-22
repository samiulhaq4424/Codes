class Solution {
public:
    int findMinSwaps(string source, string destination) {
        int len = source.length();
        queue<string> pending;
        unordered_map<string, int> visited;
        pending.push(source);
        visited[source] = 1;
        int steps = 0;

        while (!pending.empty()) {
            int queueSize = pending.size();
            for (int i = 0; i < queueSize; i++) {
                string current = pending.front();
                pending.pop();
                if (current == destination) return steps;

                for (int j = steps; j < len; j++) {
                    for (int k = j + 1; k < len; k++) {
                        string next = current;
                        swap(next[j], next[k]);
                        if (visited.find(next) == visited.end() && next[steps] == destination[steps]) {
                            pending.push(next);
                            visited[next] = 1;
                        }
                    }
                }
            }
            steps++;
        }
        return steps;
    }

    int kSimilarity(string str1, string str2) {
        string reducedSource, reducedTarget;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                reducedSource += str1[i];
                reducedTarget += str2[i];
            }
        }
        return findMinSwaps(reducedSource, reducedTarget);
    }
};