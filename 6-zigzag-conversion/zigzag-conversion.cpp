class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }

        vector<string> matrixRows(numRows, "");
        int activeRow = 0;
        int verticalStep = 1;

        for (char symbol : s) {
            matrixRows[activeRow] += symbol;

            if (activeRow == 0) {
                verticalStep = 1;
            } else if (activeRow == numRows - 1) {
                verticalStep = -1;
            }

            activeRow += verticalStep;
        }

        string structuredResult = "";
        for (const string& individualRow : matrixRows) {
            structuredResult += individualRow;
        }

        return structuredResult;
    }
};