class Solution {
public:
    void backtrack(string& num, int target, int idx, long long cur_val, long long prev_op, string expr, vector<string>& ans) {
        if (idx == num.length()) {
            if (cur_val == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int i = idx; i < num.length(); i++) {
            if (i > idx && num[idx] == '0') {
                break;
            }

            string part = num.substr(idx, i - idx + 1);
            long long val = stoll(part);

            if (idx == 0) {
                backtrack(num, target, i + 1, val, val, part, ans);
            } else {
                backtrack(num, target, i + 1, cur_val + val, val, expr + "+" + part, ans);
                backtrack(num, target, i + 1, cur_val - val, -val, expr + "-" + part, ans);
                backtrack(num, target, i + 1, cur_val - prev_op + prev_op * val, prev_op * val, expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) {
            return ans;
        }
        backtrack(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};