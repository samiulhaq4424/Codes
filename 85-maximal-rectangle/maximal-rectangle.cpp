class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;

        vector<vector<int>> leftWidth(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (j == 0) {
                        leftWidth[i][j] = 1;
                    } else {
                        leftWidth[i][j] = leftWidth[i][j - 1] + 1;
                    }

                    int minWidth = leftWidth[i][j];
                    for (int k = i; k >= 0; k--) {
                        if (leftWidth[k][j] < minWidth) {
                            minWidth = leftWidth[k][j];
                        }
                        if (minWidth == 0) {
                            break;
                        }
                        int currentArea = minWidth * (i - k + 1);
                        if (currentArea > maxArea) {
                            maxArea = currentArea;
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};