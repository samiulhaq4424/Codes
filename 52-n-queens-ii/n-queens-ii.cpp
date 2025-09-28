class Solution {
public:
    int helper(int &count, int row, int n, vector<int>& upperCol,
                vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
        if (row == n) {
            return 1;
        }
        for (int col = 0; col < n; col++) {
            if (upperCol[col] == 0 && lowerDiagonal[col + row] == 0 &&
                upperDiagonal[(n - 1) + col - row] == 0) {
                upperCol[col] = 1;
                lowerDiagonal[col + row] = 1;
                upperDiagonal[(n - 1) + col - row] = 1;
                count+= helper(count, row + 1, n, upperCol, lowerDiagonal, upperDiagonal);
                upperCol[col] = 0;
                lowerDiagonal[col + row] = 0;
                upperDiagonal[(n - 1) + col - row] = 0;
            }
        }
        return 0;
    }

    int totalNQueens(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> upperCol(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        int count = 0;
        helper(count, 0, n, upperCol, lowerDiagonal, upperDiagonal);
        return count;
    }
};