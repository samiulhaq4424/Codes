class Solution {
    int memo[301][27];
    
    int getDist(int a, int b) {
        if (a == 26) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
    
    int solve(const string& word, int pos, int other) {
        if (pos == word.length()) return 0;
        if (memo[pos][other] != -1) return memo[pos][other];
        
        int curr = word[pos] - 'A';
        int prev = pos == 0 ? 26 : word[pos - 1] - 'A';
        
        int movePrev = getDist(prev, curr) + solve(word, pos + 1, other);
        int moveOther = getDist(other, curr) + solve(word, pos + 1, prev);
        
        return memo[pos][other] = min(movePrev, moveOther);
    }
    
public:
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return solve(word, 0, 26);
    }
};