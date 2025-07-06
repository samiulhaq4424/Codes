class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> levelLengths;
        int maxLength = 0;
        int currentLength = 0;
        int level = 0;
        bool isFile = false;
        
        input += '\n';
        
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '\n') {
                if (isFile) {
                    int pathLength = currentLength;
                    for (int j = 0; j < level; j++) {
                        pathLength += levelLengths[j] + 1;
                    }
                    maxLength = max(maxLength, pathLength);
                } else {
                    while (levelLengths.size() <= level) {
                        levelLengths.push_back(0);
                    }
                    levelLengths[level] = currentLength;
                }
                
                currentLength = 0;
                level = 0;
                isFile = false;
                continue;
            }
            
            if (input[i] == '\t') {
                level++;
                continue;
            }
            
            if (input[i] == '.') {
                isFile = true;
            }
            
            currentLength++;
        }
        
        return maxLength;
    }
};