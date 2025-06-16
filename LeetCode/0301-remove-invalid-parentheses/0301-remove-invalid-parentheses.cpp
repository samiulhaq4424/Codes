class Solution {
public:
    int countInvalid(string input) {
        stack<char> parenStack;
        for (char c : input) {
            if (c == '(') {
                parenStack.push(c);
            } else if (c == ')') {
                if (parenStack.empty() || parenStack.top() == ')') {
                    parenStack.push(c);
                } else {
                    parenStack.pop();
                }
            }
        }
        return parenStack.size();
    }

    void generateValid(unordered_set<string>& results, unordered_set<string>& visited, vector<string>& output, string current, int removalsLeft) {
        if (removalsLeft == 0) {
            if (countInvalid(current) == 0 && results.find(current) == results.end()) {
                results.insert(current);
                output.push_back(current);
            }
            return;
        }
        for (int i = 0; i < current.size(); i++) {
            string next = current.substr(0, i) + current.substr(i + 1);
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                generateValid(results, visited, output, next, removalsLeft - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int minRemovals = countInvalid(s);
        unordered_set<string> results, visited;
        vector<string> output;
        generateValid(results, visited, output, s, minRemovals);
        return output;
    }
};