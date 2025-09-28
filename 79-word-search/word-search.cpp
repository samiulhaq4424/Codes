#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int ind, int X, int Y, int wordSize, int n, int m, int dirX[],
                int dirY[], vector<vector<bool>>& visited, string& word,
                vector<vector<char>>& board) {
        // current cell must match current character
        if (board[X][Y] != word[ind]) return false;

        // base case: last character matched
        if (ind == wordSize - 1) return true;

        visited[X][Y] = true;

        for (int i = 0; i < 4; i++) {
            int nextX = X + dirX[i];
            int nextY = Y + dirY[i];
            if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m &&
                !visited[nextX][nextY]) {
                if (helper(ind + 1, nextX, nextY, wordSize, n, m, dirX, dirY,
                           visited, word, board)) {
                    return true;
                }
            }
        }

        visited[X][Y] = false; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int dirX[] = {1, 0, 0, -1};
        int dirY[] = {0, -1, 1, 0};
        int n = board.size();
        int m = board[0].size();
        int wordSize = word.size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(0, i, j, wordSize, n, m, dirX, dirY, visited, word,
                           board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
