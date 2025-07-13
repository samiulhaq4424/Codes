class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal) return false;
        
        unordered_map<int, bool> memo;
        vector<bool> used(maxChoosableInteger + 1, false);
        
        return canWin(maxChoosableInteger, desiredTotal, 0, used, memo);
    }
    
private:
    bool canWin(int maxInt, int total, int state, vector<bool>& used, unordered_map<int, bool>& memo) {
        if (memo.count(state)) return memo[state];
        
        for (int i = 1; i <= maxInt; i++) {
            if (!used[i]) {
                used[i] = true;
                if (total - i <= 0 || !canWin(maxInt, total - i, state | (1 << i), used, memo)) {
                    used[i] = false;
                    memo[state] = true;
                    return true;
                }
                used[i] = false;
            }
        }
        
        memo[state] = false;
        return false;
    }
};