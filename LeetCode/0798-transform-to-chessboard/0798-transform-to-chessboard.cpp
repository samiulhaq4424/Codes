class Solution {
public:
    int movesToChessboard(vector<vector<int>>& grid) {
        int size = grid.size();
        int rowBalance = 0, colBalance = 0;

        for (int r = 0; r < size; r++) {
            rowBalance += grid[r][0] ? 1 : -1;
            for (int c = 0; c < size; c++) {
                if (r == 0) colBalance += grid[0][c] ? 1 : -1;
                if ((grid[r][0] ^ grid[0][0]) ^ (grid[r][c] ^ grid[0][c])) return -1;
            }
        }

        if (abs(rowBalance) > 1 || abs(colBalance) > 1) return -1;

        int rowSwaps = 0, colSwaps = 0;
        int rowZeros = 0, colZeros = 0;

        for (int i = 0; i < size; i++) {
            if (i % 2) {
                rowSwaps += grid[i][0];
                colSwaps += grid[0][i];
            }
            rowZeros += grid[i][0] == 0;
            colZeros += grid[0][i] == 0;
        }

        int targetZeros = size / 2;
        if (size % 2) {
            rowSwaps = rowZeros == targetZeros ? rowSwaps : (targetZeros - rowSwaps);
            colSwaps = colZeros == targetZeros ? colSwaps : (targetZeros - colSwaps);
        } else {
            rowSwaps = min(rowSwaps, targetZeros - rowSwaps);
            colSwaps = min(colSwaps, targetZeros - colSwaps);
        }

        return rowSwaps + colSwaps;
    }
};